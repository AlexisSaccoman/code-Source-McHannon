
bool is_valid_2(int i, int j, Tile t, string borderColor){

    // if i is in one of board lines except the last one
    if(i <= 0){
        // if the coordinates correspond to [0;0]
        if(i==0 && j==0){
            // check if t.top == t.left and init the border color, else return false
            if(t.top == t.left){
                borderColor = t.top;
            }
            else{
                return false;
            }
        }
        switch(j){
            case 0: // 1st column
                // 1st line
                if(i == 0){
                    if(t.top != borderColor || t.left != Res[i][j-1].right){
                        return false;
                    }
                // other lines
                }else if(i > 0){
                    if(t.top != Res[i-1][j].bottom || t.left != Res[i][j-1].right){
                        return false;
                    }
                }
            default: // col inter

            case BOARD_COLS-1: // last column
                // 1st line
                if(i == 0){
                    if(t.top != borderColor || t.right != borderColor || t.left != Res[i][j-1].right){
                        return false;
                    }
                // other lines
                }else if(i > 0){
                    if(t.top != Res[i-1][j].bottom || t.right != borderColor || t.left != Res[i][j-1].right){
                        return false;
                    }
                }

        }
    }

    // are the coordonates are [BOARD_ROWS, x] => last line
    if(i == BOARD_ROWS-1){
        switch(j){
            case 0:
            default:
            case BOARD_COLS-1:
        }
    }


    return true;
}