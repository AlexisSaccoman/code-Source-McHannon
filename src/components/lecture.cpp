
// function to read the file and put the result into tile format to put it into the board
vector <Tile> lecture(string filename){
    vector <Tile> res;
    ifstream inputFile(filename);
    // if open error => display the error message and return
    if (!inputFile.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return res;
    }

    // read the first line
    string dim;
    if (getline(inputFile, dim)) {
        // get the board dimensions
        istringstream ss(dim);
        ss >> BOARD_COLS >> BOARD_ROWS;
    } else {
        cerr << "Erreur : Le fichier est vide." << endl;
        return res;
    }

    // read the following lines
    string line;
    while (getline(inputFile, line)) {

        // suppress the spaces
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' '){
                line.erase(i, 1);
            }
        }
        
        // creation of a tile object
        Tile t("W");

        // we set the tile colors
        t.left = line[0];
        t.top = line[1];
        t.right = line[2];
        t.bottom = line[3];
        
        // we add the tile to the vector
        res.push_back(t);
    }

    // Close the file
    inputFile.close();

    return res;

}