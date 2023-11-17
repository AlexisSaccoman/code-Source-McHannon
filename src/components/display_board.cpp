
void display_board(vector<Tile> Board){

    for(int i = 0 ; i < BOARD_ROWS; i++){
        // topline
        cout << " ";
        for(int j = 0 ; j < BOARD_COLS; j++){
            cout << Board[i+j].top << "   ";
        }
        cout << endl;

        // midline
        for(int j = 0 ; j < BOARD_COLS; j++){
            cout << Board[i+j].left << " " << Board[i+j].right << " ";
        }
        cout << endl;


        // bottomline
        cout << " ";
        for(int j = 0 ; j < BOARD_COLS; j++){
            cout << Board[i+j].bottom << "   ";
        }
        cout << endl;
    }
}


void fill_BoardRes_with_Res(){
    for(int i = 0 ; i < BOARD_COLS; i++){
        for(int j = 0 ; j < BOARD_ROWS; j++){
            BoardRes.push_back(Res[i][j]);
        }
    }
}


// affichage en couleur

void setTextColor(const string& color) {
    if (color == "R") {
        cout << "\033[31m"; // Rouge
    } else if (color == "B") {
        cout << "\033[34m"; // Bleu
    } else if (color == "W") {
        cout << "\033[37m"; // Blanc
    } else if (color == "G") {
        cout << "\033[32m"; // Vert
    } else {
        cout << "\033[0m";  // Rétablir la couleur par défaut
    }
}

void display_board_color(vector<Tile> Board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        // topline
        cout << " ";
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i + j].top);
            cout << Board[i + j].top << "   \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;

        // midline
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i + j].left);
            cout << Board[i + j].left << " ";
            setTextColor(Board[i + j].right);
            cout << Board[i + j].right << " \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;

        // bottomline
        cout << " ";
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i + j].bottom);
            cout << Board[i + j].bottom << "   \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;
    }
}

// display board color pour un vector de vector de Tile
void display_board_color(vector<vector<Tile>> Board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        // topline
        cout << " ";
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i][j].top);
            cout << Board[i][j].top << "   \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;

        // midline
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i][j].left);
            cout << Board[i][j].left << " ";
            setTextColor(Board[i][j].right);
            cout << Board[i][j].right << " \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;

        // bottomline
        cout << " ";
        for (int j = 0; j < BOARD_COLS; j++) {
            setTextColor(Board[i][j].bottom);
            cout << Board[i][j].bottom << "   \033[0m"; // Rétablir la couleur par défaut
        }
        cout << endl;
    }
}