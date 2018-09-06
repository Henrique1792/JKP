#include "game.h"
using namespace std;


game::game(){
    std::vector<int> getFromFile=getLine();
    rows=getFromFile[0];
    columns=getFromFile[1];

    getFromFile.clear();


    table.resize(rows); 
    for (int i=0; i<columns; i++)
        table[i].resize(columns);


};

game::~game(void){
};

void game::setGame(){ 
};

