
bool is_valid(int i, int j, Tile t){

    // are the coordinates in the board ?
    if(i < 0 || i >= BOARD_ROWS || j < 0 || j >= BOARD_COLS){
        return false;
    }

    // is the tile corresponding to the coordinates in the board free ?
    if(Res[i][j].state != 0){
        return false;
    }

    // is the tile in one corner of the board, with external borders of the same color
    if ((i == 0 && j == 0) || (i == 0 && j == BOARD_COLS - 1) || (i == BOARD_ROWS - 1 && j == 0) || (i == BOARD_ROWS - 1 && j == BOARD_COLS - 1)) {
        if(t.top != t.left || t.left != t.right || t.right != t.bottom){
            return false;
        }
    }

    // is the bottom border of the tile matching the top border of the tile above ?
    if (i > 0 && Res[i - 1][j].bottom != t.top) {
        return false;
    }

    // is the top border of the tile matching the bottom border of the tile below ?
    if (i < BOARD_ROWS - 1 && Res[i + 1][j].top != t.bottom) {
        return false;
    }

    // is the left border of the tile matching the right border of the tile to the left ?
    if (j > 0 && Res[i][j - 1].right != t.left) {
        return false;
    }

    // is the right border of the tile matching the left border of the tile to the right ?
    if (j < BOARD_COLS - 1 && Res[i][j + 1].left != t.right) {
        return false;
    }

    // is the tile placed on the border of the board ?
    if ((i == 0 || i == BOARD_ROWS - 1 || j == 0 || j == BOARD_COLS - 1)) {
        // are the tiles color matching the other border tiles colors ?
        if(t.top != t.left || t.left != t.right || t.right != t.bottom){
            return false;
        }
    }

    // then the tile can be placed on those coordinates
    return true;
}