

bool solve_sequential_helper(vector<Tile>& BoardTileUsed, vector<vector<Tile>>& BoardSolvePartiel, int row, int col) {
    
    // Si la solution partielle est complète, retourner true
    if (row == BOARD_ROWS) {
        return true;
    }

    //! debug
    cout << "row " << row << " col " << col << endl;

    // Parcourir toutes les tuiles disponibles
    for (int tileIdx = 0; tileIdx < BoardTileUsed.size(); tileIdx++) {
        if (!BoardTileUsed[tileIdx].state) { // Si la tuile n'a pas encore été utilisée dans la solution partielle actuelle
            
            BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx]; // Placer la tuile dans la solution partielle
            string borderColor = "";

            //! debug
            cout << "# Flag 3" << endl;
            cout << "tileIdx : " << tileIdx << endl;
            
            if (is_valid_3(row, col, BoardTileUsed[tileIdx], borderColor, BoardSolvePartiel)) { // Si la solution partielle est valide
                
                //! debug
                cout << "# Flag 4" << endl;

                // Calculer les coordonnées de la prochaine tuile à placer
                int nextRow=0, nextCol=0;
                if( col == BOARD_COLS-1){
                    nextRow = col+1;
                    nextCol = 0;
                }else{
                    nextRow = row;
                    nextCol = col+1;
                }

                //! debug
                cout << "row " << row << " col " << col << endl;
                cout << "nextRow " << nextRow << " nextCol " << nextCol << endl;

                // Marquer la tuile comme utilisée
                BoardTileUsed[tileIdx].state = true;
                // attribuer la couleur de la tuile de la solution partielle à celle testée
                BoardSolvePartiel[row][col] = BoardTileUsed[tileIdx];

                //! debug
                // on affiche la solution partielle 
                cout << "Solution partielle : " << endl;
                for(int i = 0 ; i < BOARD_COLS; i++){
                    for(int j = 0 ; j < BOARD_ROWS; j++){
                        cout << BoardSolvePartiel[i][j].left << BoardSolvePartiel[i][j].top << BoardSolvePartiel[i][j].right << BoardSolvePartiel[i][j].bottom << " ";
                    }
                    cout << endl;
                }
                // on affiche la liste des tuiles utilisées
                cout << "Tuiles utilisées : ";
                for(int i = 0 ; i < BoardTileUsed.size(); i++){
                    cout << BoardTileUsed[i].state << " ";
                }
                cout << endl;

                cout << endl;

                //! debug
                cout << "# Flag 1" << endl;
                if (solve_sequential_helper(BoardTileUsed, BoardSolvePartiel, nextRow, nextCol)) { // Appeler la fonction d'aide récursive
                    return true;
                }
                cout << "# Flag 2" << endl;
                
                BoardTileUsed[tileIdx].state = false; // Marquer la tuile comme non utilisée
            }
        }
    }


    return false;
}


// fonction de résolution séquentielle du puzzle qui appelle la fonction d'aide récursive solve_sequential_helper
bool solve_sequential(const vector<Tile>& BoardInit) {

    

    // Initialiser BoardSolvePartiel avec des tuiles vides
    vector<vector<Tile>> BoardSolvePartiel = vector<vector<Tile>>(BOARD_ROWS, vector<Tile>(BOARD_COLS));
    
    // Copier les tuiles initiales dans BoardTileUsed
    vector <Tile> BoardTileUsed;
    for( int i = 0 ; i < BOARD_COLS; i++){
        for(int j = 0 ; j < BOARD_ROWS; j++){
            BoardTileUsed.push_back(BoardInit[i+j]);
        }
    }

    // Mesurer le temps d'exécution
    clock_t startTime = clock();

    // Appeler la fonction d'aide récursive
    bool solutionFound = solve_sequential_helper(BoardTileUsed, BoardSolvePartiel, 0, 0);

    // Mesurer le temps d'exécution
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    execTimes.push_back(vector<double>{executionTime, 0.0, 0.0});

    // Afficher la solution si trouvée
    if (solutionFound) {
        // on copie le contenu de BoardSolvePartiel dans Res et on affiche le plateau résolu
        Res = BoardSolvePartiel;
        fill_BoardRes_with_Res();
        display_board(BoardRes);
    } else {
        cout << "No solution found." << endl;
    }

    return solutionFound;
}