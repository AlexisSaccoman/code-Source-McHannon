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
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <cstddef>
#include <future>
#include <atomic>
#include <stack>

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
vector <string> fileNames = {"../assets/data66.txt"};


// METHODS
#include "components/lecture.cpp"
#include "components/display_board.cpp"
#include "components/is_valid_4.cpp"

#include "components/solve_sequential.cpp"
//#include "components/solve_threadPool.cpp"
#include "components/solve_otherMethod_v2.cpp"


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
        cout << "#========= Sequentiel - 1st Exec time =========#" << endl;
        solve_sequential(BoardInit);
        cout << "#==============================================#" << endl;
        cout << "#======== threadPool - non fonctionnel ========#" << endl;
        //solve_threadPool(BoardInit, 4);
        cout << "#==============================================#" << endl;
        cout << "#======== OtherMethod - 2nd Exec time =========#" << endl;
        solve_otherMethod(BoardInit);
        cout << "#==============================================#" << endl;
    }

    // TIME DISPLAY
    int a = BOARD_COLS;
    cout << "#============== Execution Times ===============#" << endl;
    for(vector <double> t : execTimes){
        cout << "Exec Time : "<< a <<"x"<< a <<" => " << t[0] << "sec" << endl;
    }
    cout << "#==============================================#" << endl;
    
    return 0;
}
