
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