
bool is_valid_3(int i, int j, const Tile& t, string& borderColor, vector<vector<Tile>> BoardSolvePartiel) {
    
    if (j == 0) {  // 1ère colonne -------------------------------------------------------------------------
        
        // [0 ; 0]
        if (i == 0) {
            if (t.top == t.left) {
                borderColor = t.top;
                return true;
            } else {
                return false;
            }
        }
        
        // [x ; 0]
        else if (i > 0 && i < BOARD_ROWS - 1) {
            if (t.top != BoardSolvePartiel[i - 1][j].bottom || t.left != borderColor) {
                return false;
            } else {
                return true;
            }
        }
        
        // [BOARD_ROWS ; 0]
        else if(i == BOARD_ROWS - 1){
            if(t.left != borderColor || t.top != BoardSolvePartiel[i-1][j].bottom){
                return false;
            } else {
                return true;
            }
        }

    } else if (j == BOARD_COLS - 1) {  // Dernière colonne --------------------------------------------------
        // [0 ; BOARD_COLS - 1]
        if (i == 0) {
            if (t.top != BoardSolvePartiel[i - 1][j].bottom || t.left == t.bottom || t.bottom != borderColor) {
                return false;
            } else {
                return true;
            }
        }
        
        // [x ; BOARD_COLS - 1]
        else if (i > 0 && i < BOARD_ROWS - 1) {
            if (t.left != BoardSolvePartiel[i][j-1].right || t.top != BoardSolvePartiel[i-1][j].bottom) {
                return false;
            } else {
                return true;
            }
        }
        
        // [BOARD_ROWS - 1 ; BOARD_COLS - 1]
        else if(i == BOARD_ROWS - 1){
            if(t.left != BoardSolvePartiel[i][j-1].right || t.top != BoardSolvePartiel[i-1][j].bottom || t.bottom != t.right || t.right != borderColor || t.bottom != borderColor){
                return false;
            } else {
                return true;
            }
        }
    } else {  // Colonnes intermédiaires -----------------------------------------------------------------
        // [0 ; x]
        if (i == 0) {
            if (t.top != BoardSolvePartiel[i - 1][j].bottom || t.top != borderColor || t.left == BoardSolvePartiel[i][j-1].right) {
                return false;
            } else {
                return true;
            }
        }
        
        // [x ; x]
        else if (i > 0 && i < BOARD_ROWS - 1) {
            if (t.top != BoardSolvePartiel[i - 1][j].bottom || t.left == BoardSolvePartiel[i][j-1].right) {
                return false;
            } else {
                return true;
            }
        }
        
        // [BOARD_ROWS - 1 ; x]
        else if(i == BOARD_ROWS - 1){
            if(t.left != BoardSolvePartiel[i][j-1].right || t.top != BoardSolvePartiel[i-1][j].bottom || t.bottom != borderColor){
                return false;
            } else {
                return true;
            }
        }
    }    

    return true;
}
