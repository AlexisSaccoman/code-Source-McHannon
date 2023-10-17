#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <sstream>



using namespace std;

//---------------------- GLOBAL VARIABLES -----------------------//
int BOARD_ROWS = 0;
int BOARD_COLS = 0;
int TILE_COUNT = 24;

#include "components/Tile.h"
#include "components/lecture.cpp"

int main(){

    vector <vector<Tile>> Res;
    

    // data 1st line => board size
    // data Xth line => 1 tile => data order => left/top/right/bottom

    vector<Tile> Board44 = lecture("../assets/data44.txt");
    //vector<Tile> Board55 = lecture("../assets/data55.txt");
    //vector<Tile> Board66 = lecture("../assets/data66.txt");



    // DISPLAY
    cout << "#================= Board data =================#" << endl;
    cout << "Dimensions : " << BOARD_COLS << "x" << BOARD_ROWS << endl;
    
    for(int i = 0 ; i < BOARD_COLS; i++){
        for(int j = 0 ; j < BOARD_ROWS; j++){
            cout << Board44[i+j].left << Board44[i+j].top << Board44[i+j].right << Board44[i+j].bottom << " ";
        }
        cout << endl;
    }
    cout << "#==============================================#" << endl;
    cout << "#=============== Board solution ===============#" << endl;
    cout << "#==============================================#" << endl;

    return 0;
}