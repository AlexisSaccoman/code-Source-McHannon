
bool is_valid_4(int row, int col, Tile t, vector<vector<Tile>>& BoardSolvePartiel, string& borderColor){

    if(row == 0){ // première ligne

        if(col == 0){ // première colonne
            if(t.left == t.top){
                borderColor = t.left;
                return true;
            }
        }else if(col > 0 && col < BOARD_COLS-1){ // colonnes intermédiaires
            if(t.top == borderColor && t.left == BoardSolvePartiel[row][col-1].right){
                return true;
            }
        }else{ // dernière colonne
            if(t.top == borderColor && t.right == borderColor && t.left == BoardSolvePartiel[row][col-1].right){
                return true;
            }
        }

    }else if(row > 0 && row < BOARD_ROWS-1){ // lignes intermédiaires
        if(col == 0){ // première colonne
            if(t.left == borderColor && t.top == BoardSolvePartiel[row-1][col].bottom){
                return true;
            }
        }else if(col > 0 && col < BOARD_COLS-1){ // colonnes intermédiaires
            if(t.left == BoardSolvePartiel[row][col-1].right && t.top == BoardSolvePartiel[row-1][col].bottom){
                return true;
            }
        }else{ // dernière colonne
            if(t.top == BoardSolvePartiel[row-1][col].bottom && t.left == BoardSolvePartiel[row][col-1].right && t.right == borderColor){
                return true;
            }
        }
    }else{ // dernière ligne
        if(col == 0){ // première colonne
            if(t.left == borderColor && t.top == BoardSolvePartiel[row-1][col].bottom && t.bottom == borderColor){
                return true;
            }
        }else if(col > 0 && col < BOARD_COLS-1){ // colonnes intermédiaires
            if(t.left == BoardSolvePartiel[row][col-1].right && t.top == BoardSolvePartiel[row-1][col].bottom && t.bottom == borderColor){
                return true;
            }
        }else{ // dernière colonne
            if(t.top == BoardSolvePartiel[row-1][col].bottom && t.left == BoardSolvePartiel[row][col-1].right && t.right == borderColor && t.bottom == borderColor){
                return true;
            }
        }
    }

    return false;
}