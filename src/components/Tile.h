class Tile{
    private:

    public:
        bool state;
        string top;
        string left;
        string right;
        string bottom;

        Tile(string white){
            state = 0;
            top = white;
            left = white;
            right = white;
            bottom = white;
        }
};