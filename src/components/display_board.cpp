
void display_board(vector<Tile> Board){

    int nbr_tuiles = BOARD_COLS * BOARD_ROWS;
    int lines = nbr_tuiles*3;
    int cols = nbr_tuiles*3;


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