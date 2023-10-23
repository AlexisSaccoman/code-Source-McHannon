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
#include "components/display_board.cpp"
#include "components/solve_threadPool.cpp"
#include "components/solve_otherMethod.cpp"

int main(){
    
    // data 1st line => board size
    // data Xth line => 1 tile => data order => left/top/right/bottom

    vector<Tile> BoardRes;
    vector <vector<double>> execTimes;
    vector <vector<Tile>> Res;

    vector <string> fileNames = {"../assets/data44.txt", "../assets/data55.txt", "../assets/data66.txt"};

    for(string fName : fileNames){
        // READ
        vector<Tile> BoardInit = lecture(fName);

        // BOARD SOLUTION DISPLAY
        cout << "#================= Board data =================#" << endl;
        cout << "Dimensions : " << BOARD_COLS << "x" << BOARD_ROWS << endl;
        
        for(int i = 0 ; i < BOARD_COLS; i++){
            for(int j = 0 ; j < BOARD_ROWS; j++){
                cout << BoardInit[i+j].left << BoardInit[i+j].top << BoardInit[i+j].right << BoardInit[i+j].bottom << " ";
            }
            cout << endl;
        }
        cout << "#==============================================#" << endl;
        cout << "#=============== Board solution ===============#" << endl;
        display_board(BoardInit);
        cout << "#==============================================#" << endl;
    }

    // TIME DISPLAY
    int a = 4;
    cout << "#============== Execution Times ===============#" << endl;
    for(vector <double> t : execTimes){
        cout << "Solving the "<< a <<"x"<< a <<" with thread pool : " << t[0] << "sec" << endl;
        cout << "Solving the "<< a <<"x"<< a <<" with other method : " << t[1] << "sec" << endl;
        a += 1;
    }
    cout << "#==============================================#" << endl;
    
    return 0;
}