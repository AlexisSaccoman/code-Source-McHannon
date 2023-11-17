
mutex mtx;  // Mutex pour assurer une synchronisation correcte

bool solve_parallel_helper(vector<Tile>& BoardTileUsed, vector<vector<Tile>>& BoardSolvePartiel, string& borderColor, int row, int col) {
    // Si la solution partielle est complète, retourner true
    if (row == BOARD_ROWS-1 && col == BOARD_COLS-1) {
        return true;
    }

    // Parcourir toutes les tuiles disponibles
    vector<thread> threads;
    for (int tileIdx = 0; tileIdx < BoardTileUsed.size(); tileIdx++) {
        if (!BoardTileUsed[tileIdx].state) { // Si la tuile n'a pas encore été utilisée dans la solution partielle actuelle
            BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx]; // Placer la tuile dans la solution partielle

            threads.push_back(thread([&]() {
                // Si la solution partielle est valide
                if (is_valid_4(row, col, BoardTileUsed[tileIdx], BoardSolvePartiel, borderColor)) {
                    // Calculer les coordonnées de la prochaine tuile à placer
                    int nextRow = 0;
                    int nextCol = 0;
                    if (col == BOARD_COLS-1 && row < BOARD_ROWS-1) {
                        nextRow = row + 1;
                        nextCol = 0;
                    } else if (col < BOARD_COLS-1) {
                        nextRow = row;
                        nextCol = col + 1;
                    } else if (col == BOARD_COLS-1 && row == BOARD_ROWS-1) {
                        nextRow = row;
                        nextCol = col;
                    }

                    // Utiliser un verrou pour assurer une synchronisation correcte
                    lock_guard<mutex> lock(mtx);

                    // Marquer la tuile comme utilisée
                    BoardTileUsed[tileIdx].state = true;

                    // Attribuer la couleur de la tuile de la solution partielle à celle testée
                    BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx];

                    // Appeler la fonction d'aide récursive 
                    if (solve_parallel_helper(BoardTileUsed, BoardSolvePartiel, borderColor, nextRow, nextCol)) {             
                        return true;
                    }
                }

                // Marquer la tuile comme non utilisée
                BoardTileUsed[tileIdx].state = false;
            }));
        }
    }

    // Attendre que tous les threads se terminent
    for (auto& thread : threads) {
        thread.join();
    }

    return false;
}

// Fonction de résolution parallèle du puzzle
bool solve_parallel(const vector<Tile>& BoardInit) {
    // Initialiser BoardSolvePartiel avec des tuiles vides
    vector<vector<Tile>> BoardSolvePartiel(BOARD_ROWS, vector<Tile>(BOARD_COLS));

    // Copier les tuiles initiales dans BoardTileUsed
    vector<Tile> BoardTileUsed = BoardInit;

    string borderColor = "";

    // Mesurer le temps d'exécution
    clock_t startTime = clock();

    // Appeler la fonction d'aide récursive
    bool solutionFound = solve_parallel_helper(BoardTileUsed, BoardSolvePartiel, borderColor, 0, 0);

    // Mesurer le temps d'exécution
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    execTimes.push_back(vector<double>{executionTime, 0.0, 0.0});

    // Afficher la solution si trouvée
    if (solutionFound) {
        Res = BoardSolvePartiel;
        fill_BoardRes_with_Res();
        display_board_color(BoardRes);
    } else {
        cout << "No solution found." << endl;
    }

    return solutionFound;
}

bool solve_otherMethod(const vector<Tile>& BoardInit){
    return solve_parallel(BoardInit);
}
