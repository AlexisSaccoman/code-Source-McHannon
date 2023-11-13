#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <thread>

using namespace std;

// OBJECTS
#include "components/Tile.h"

//---------------------- GLOBAL VARIABLES -----------------------//
int BOARD_ROWS = 0;
int BOARD_COLS = 0;
const int TILE_COUNT = BOARD_ROWS*BOARD_COLS;

vector <Tile> BoardRes;
vector <vector<double>> execTimes;
vector<vector<Tile>> Res(BOARD_ROWS, vector<Tile>(BOARD_COLS));
vector <string> fileNames = {"../assets/data44.txt"};


// METHODS
#include "components/lecture.cpp"
#include "components/display_board.cpp"
//#include "components/is_valid.cpp"
//#include "components/is_valid_2.cpp"
#include "components/is_valid_3.cpp"

#include "components/solve_sequential.cpp"
#include "components/solve_threadPool.cpp"
#include "components/solve_otherMethod.cpp"


// MAIN --> READ FILE & SOLVE --> DISPLAY
int main(){
    
    // data 1st line => board size
    // data Xth line => 1 tile => data order => left/top/right/bottom

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
        // SOLVE & DISPLAY
        solve_sequential(BoardInit);
        // solve_threadPool(BoardInit);
        // solve_otherMethod(BoardInit);
        cout << "#==============================================#" << endl;
    }

    // TIME DISPLAY
    int a = 4;
    cout << "#============== Execution Times ===============#" << endl;
    for(vector <double> t : execTimes){
        cout << "Sequential backtracking : "<< a <<"x"<< a <<" => " << t[0] << "sec" << endl;
        cout << "Thread pool backtracking : "<< a <<"x"<< a <<" => " << t[1] << "sec" << endl;
        cout << "Other PM backtracking : "<< a <<"x"<< a <<" => " << t[2] << "sec" << endl;
        a += 1;
    }
    cout << "#==============================================#" << endl;
    
    return 0;
}