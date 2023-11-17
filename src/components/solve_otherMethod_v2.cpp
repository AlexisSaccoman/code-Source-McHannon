

mutex mtx;  // Mutex pour assurer une synchronisation correcte

// Fonction de backtracking itérative pour résoudre le puzzle
bool solve_parallel_helper(vector<Tile>& BoardTileUsed, vector<vector<Tile>>& BoardSolvePartiel, string& borderColor) {
    stack<tuple<int, int, int>> stack;  // Pile pour l'approche itérative

    stack.push(make_tuple(0, 0, 0));  // Ajouter le premier état à la pile

    // Parcourir la pile jusqu'à ce qu'elle soit vide
    while (!stack.empty()) {
        // Récupérer l'état courant
        auto [row, col, tileIdx] = stack.top();
        stack.pop(); // Enlever l'état courant de la pile

        if (row == BOARD_ROWS - 1 && col == BOARD_COLS - 1) {
            return true;  // Solution trouvée
        }

        // Essayer la tuile courante
        if (!BoardTileUsed[tileIdx].state) {
            BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx];

            // Si la tuile courante est valide, essayer l'état suivant
            if (is_valid_4(row, col, BoardTileUsed[tileIdx], BoardSolvePartiel, borderColor)) {
                int nextRow = 0, nextCol = 0;
                if (col == BOARD_COLS - 1 && row < BOARD_ROWS - 1) {
                    nextRow = row + 1;
                    nextCol = 0;
                } else if (col < BOARD_COLS - 1) {
                    nextRow = row;
                    nextCol = col + 1;
                } else if (col == BOARD_COLS - 1 && row == BOARD_ROWS - 1) {
                    nextRow = row;
                    nextCol = col;
                }
                else
                {// Si la tuile courante n'est pas valide, essayer la tuile suivante
                    lock_guard<mutex> lock(mtx);
                    BoardTileUsed[tileIdx].state = true;
                    BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx];
                }

                stack.push(make_tuple(nextRow, nextCol, 0));  // Ajouter l'état suivant à la pile
            }

            {// Si la tuile courante n'est pas valide, essayer la tuile suivante
                lock_guard<mutex> lock(mtx);
                BoardTileUsed[tileIdx].state = false;
            }
        }

        // Essayer la tuile suivante
        if (tileIdx + 1 < BoardTileUsed.size()) {
            stack.push(make_tuple(row, col, tileIdx + 1));
        }
    }

    return false;
}

bool solve_parallel(const vector<Tile>& BoardInit) {
    vector<vector<Tile>> BoardSolvePartiel(BOARD_ROWS, vector<Tile>(BOARD_COLS));
    vector<Tile> BoardTileUsed = BoardInit;
    string borderColor = "";

    clock_t startTime = clock();

    bool solutionFound = solve_parallel_helper(BoardTileUsed, BoardSolvePartiel, borderColor);

    // Début de la mesure du temps d'exécution
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    execTimes.push_back(vector<double>{executionTime, 0.0, 0.0});

    // Afficher le résultat
    if (solutionFound) {
        Res = BoardSolvePartiel;
        fill_BoardRes_with_Res();
        display_board_color(BoardRes);
    } else {
        cout << "No solution found." << endl;
    }

    return solutionFound;
}

bool solve_otherMethod(const vector<Tile>& BoardInit) {
    return solve_parallel(BoardInit);
}
