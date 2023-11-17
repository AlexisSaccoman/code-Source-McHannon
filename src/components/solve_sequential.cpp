

bool solve_sequential_helper(vector<Tile>& BoardTileUsed, vector<vector<Tile>>& BoardSolvePartiel, string& borderColor, int row, int col) {

    // Si la solution partielle est complète, retourner true
    if (row == BOARD_ROWS-1 && col == BOARD_COLS-1) {
        return true;
    }

    // Parcourir toutes les tuiles disponibles
    for (int tileIdx = 0; tileIdx < BoardTileUsed.size(); tileIdx++) {
        if (!BoardTileUsed[tileIdx].state) { // Si la tuile n'a pas encore été utilisée dans la solution partielle actuelle
            
            BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx]; // Placer la tuile dans la solution partielle

            // Si la solution partielle est valide
            if (is_valid_4(row, col, BoardTileUsed[tileIdx], BoardSolvePartiel, borderColor)) {

                // Calculer les coordonnées de la prochaine tuile à placer
                int nextRow=0, nextCol=0;
                if( col == BOARD_COLS-1 && row < BOARD_ROWS-1){
                    nextRow = row+1;
                    nextCol = 0;
                }else if(col < BOARD_COLS-1){
                    nextRow = row;
                    nextCol = col+1;
                }else if(col == BOARD_COLS-1 && row == BOARD_ROWS-1){
                    nextRow = row;
                    nextCol = col;
                }


                // Marquer la tuile comme utilisée
                BoardTileUsed[tileIdx].state = true;

                // attribuer la couleur de la tuile de la solution partielle à celle testée
                BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx];

                // Appeler la fonction d'aide récursive 
                if(solve_sequential_helper(BoardTileUsed, BoardSolvePartiel, borderColor, nextRow, nextCol)) {             
                    return true;
                }
                
                
            }

            BoardTileUsed[tileIdx].state = false; // Marquer la tuile comme non utilisée
                
        }
    }


    return false;
}



// fonction de résolution séquentielle du puzzle qui appelle la fonction d'aide récursive solve_sequential_helper
bool solve_sequential(const vector<Tile>& BoardInit) {

    
    // Initialiser BoardSolvePartiel avec des tuiles vides
    vector<vector<Tile>> BoardSolvePartiel = vector<vector<Tile>>(BOARD_ROWS, vector<Tile>(BOARD_COLS));
    
    // Copier les tuiles initiales dans BoardTileUsed
    vector <Tile> BoardTileUsed = BoardInit;

    string borderColor = "";

    // Mesurer le temps d'exécution
    clock_t startTime = clock();

    // Appeler la fonction d'aide récursive
    bool solutionFound = solve_sequential_helper(BoardTileUsed, BoardSolvePartiel, borderColor, 0, 0);

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


