#include <iostream>
#include <string>
#include <vector>

#include "components/Plateau.h"
#include "components/Tuile.h"

using namespace std;


int main(){

    Plateau P;
    int col = 4;
    int row = 6;
    // plateau de taile 4*6 -> 4 vectors de 6 tuiles


    for(int i = 0; i<row; i++){
        vector <Tuile> row;
        for(int j = 0; j<col; j++){
            Tuile T = Tuile("W");
            row.push_back(T);
        }
        P.plateau.push_back(row);
    }

    // we display the Plateau
    for(vector <Tuile> r : P.plateau){
        for(int i = 0; i<col; i++){
            cout << i << " : " << r[i].state << endl;
        }
    }

    return 0;
}