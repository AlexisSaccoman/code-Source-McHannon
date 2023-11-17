

// Mettez à jour l'état actuel (state) en fonction de vos règles métier
void update_state(Tile& tile) {
    // Implémentez votre logique de mise à jour de l'état ici
    // Par exemple, changer l'état d'une tuile utilisée à non utilisée
    tile.state = !tile.state;
}

// Votre logique de backtracking séquentiel basée sur BFS
bool solve_sequential(const vector<Tile>& BoardInit) {

    // Initialiser la solution partielle
    vector<vector<Tile>> BoardSolvePartiel(BOARD_ROWS, vector<Tile>(BOARD_COLS));

    // Initialiser la file pour le parcours en largeur
    queue<pair<int, int>> statesQueue;  // Paires de coordonnées (row, col)
    statesQueue.push({0, 0});  // Ajouter l'état initial à la file

    // Copier les tuiles initiales dans BoardTileUsed
    vector<Tile> BoardTileUsed(BoardInit);
    string borderColor = "";

    // Démarere la mesure du temps d'exécution
    clock_t startTime = clock();

    while (!statesQueue.empty()) {
        // Récupérer les coordonnées de l'état courant
        pair<int, int> current = statesQueue.front();
        statesQueue.pop();

        int row = current.first;
        int col = current.second;

        //!debug
        cout << "row : " << row << endl;
        cout << "col : " << col << endl;
        // afficher la liste des tuiles utilisées
        cout << "BoardTileUsed : " << endl;
        for (int i = 0; i < BoardTileUsed.size(); i++) {
            cout << BoardTileUsed[i].state << " ";
        }
        cout << endl;

        // Parcourir toutes les tuiles disponibles
        for (int tileIdx = 0; tileIdx < BoardTileUsed.size(); tileIdx++) {

            if (!BoardTileUsed[tileIdx].state) { // Si la tuile n'a pas encore été utilisée dans la solution partielle actuelle
                BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx]; // Placer la tuile dans la solution partielle

                // Si la solution partielle est valide
                if (is_valid_4(row, col, BoardSolvePartiel[row][col], BoardSolvePartiel, borderColor)) {

                    // Si la solution partielle est complète, afficher la solution
                    if (row == BOARD_ROWS - 1 && col == BOARD_COLS - 1) {

                        Res = BoardSolvePartiel;
                        fill_BoardRes_with_Res();
                        display_board_color(BoardRes);


                        // Fin de la mesure du temps d'exécution
                        clock_t endTime = clock();
                        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
                        execTimes.push_back(vector<double>{executionTime, 0.0, 0.0});
                        
                        return true;
                    }

                    // Ajouter l'état suivant à la file pour exploration ultérieure
                    int nextRow = 0 , nextCol = 0;

                    if(col == BOARD_COLS-1 ){
                        nextRow = row+1;
                        nextCol = 0;
                    }else {
                        nextRow = row;
                        nextCol = col+1;
                    }
                    
                    statesQueue.push({nextRow, nextCol});

                    // Mettez à jour l'état pour passer à la case suivante
                    update_state(BoardTileUsed[tileIdx]);
                    //BoardTileUsed[tileIdx].state = 1;
                }

            }

            // Si la solution partielle n'est pas valide, on passe à la tuile suivante en supprimant la tuile courante de la solution partielle
            BoardSolvePartiel[row][col] = Tile();

        }
    }

    // Fin de la mesure du temps d'exécution
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    execTimes.push_back(vector<double>{executionTime, 0.0, 0.0});

    cout << "No solution found." << endl;
    return false;
}


