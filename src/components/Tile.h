class Tile{
    private:

    public:
        bool state;
        string top;
        string left;
        string right;
        string bottom;

        Tile(){
            state = 0;
            top = "W";
            left = "W";
            right = "W";
            bottom = "W";
        
        }

        Tile(string white){
            state = 0;
            top = white;
            left = white;
            right = white;
            bottom = white;
        }

        string toString(){
            return left + top + right + bottom;
        }
};