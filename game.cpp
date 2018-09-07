#include "game.h"
//using namespace std;

game* game::instance=0;
game* game::getInstance(){
    if(instance==0)
        instance=new game();
    return instance;
};

game::game(){
    std::vector<int> geIO=getLine();
    rows=geIO[0];
    columns=geIO[1];

    geIO.clear();

    table.resize(rows); 
    for (int i=0; i<columns; i++)
        table[i].resize(columns);

    for(int i=0; i<rows; i++){
        geIO=getLine();

        for(int j=0; j<columns; j++)
            table[i][j]=geIO[j];

        geIO.clear();
    }

};

game::~game(void){
};

void game::printGame(){
    int i, j;
    printf("rows: %d, columns: %d\n", this->rows, this->columns);

    for(i=0; i<this->rows;i++){
        for(j=0; j<this->columns; j++)
            printf("%d ", this->table[i][j]);
        printf("\n");
    }
};


bool checkWin(std::vector<std::vector<int>> table, int row, int column){
    int i, j, k=0;

    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(table[i][j]!=EMPTY)
                k++;
            if(k>2){
                break;
            } 
        } 
    }
    return (k<2 ? true:false);
}


bool checkMove(int x1, int x2){
if((x1==SCISSORS && x2==PAPER) || 
    (x1==PAPER && x2==ROCK) ||
    (x1==ROCK && x2==SCISSORS))
        return true;
    else 
        return false;
}
