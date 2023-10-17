#include <iostream>
#include <string>

using namespace std;

class Tuile{
    private:

    public:
        string state;
        string top;
        string left;
        string right;
        string bottom;

        Tuile(string white){
            top = white;
            left = white;
            right = white;
            bottom = white;
        }
};