#include "game.h"
//using namespace std;

game* game::instance=0;
extern game *teste;
extern std::vector<Movimento>caminho;

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

Movimento game::checkMove(int x, int y){
    Movimento rt;
    rt.origem[0]=x;
    rt.origem[1]=y;
    
    //Check each coordinate to move
    
}


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


bool checkJanken(int x1, int x2){
if( (x1!=EMPTY && (x2!=EMPTY)) &&
    (   (x1==SCISSORS && x2==PAPER) || 
        (x1==PAPER && x2==ROCK) ||
        (x1==ROCK && x2==SCISSORS)))
  
        return true;
    else 
        return false;
}


bool BruteCheckR(int x, int y){
    Movimento assignment;
    assignment.origem[0]=x;
    assignment.origem[1]=y;
    
    //caso estiver numa situação de fim.
    //A jogada completa estará no vetor caminho,
    //que será limpo na função externa a recursão.
    if(checkWin(teste->table, teste->rows, teste->columns))
        return true;

    //checar movimentos possíveis
    //p/ cada movimento possível
    //caminho.push_back();
    //if(BruteCheckR(novo x, novo y))
        //return true - todas as jogadas no caminho.
    //else
        //pop resultado do caminho
    
        
        
    //return false;
    
    
}


void BruteCheck(game *teste){
    int i, j;
    for(i=0;i<teste->rows;i++){
        for(j=0;j<teste->columns; j++)
            if(teste->table[i][j]!=EMPTY)
               BruteCheckR(i, j);
    }
}


