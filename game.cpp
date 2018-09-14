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


Movimento **checkMove(int x, int y, int *nMoves){
    Movimento **rt;    
    int i=0;
    //Check each possible move

    //left
    if((y+1)<teste->columns){
        if(checkJanken(teste->table[x][y], teste->table[x][y+1])){
            rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
            rt[i]->origem[0]=x;
            rt[i]->origem[1]=y;
            rt[i]->destino[0]=x;
            rt[i]->destino[1]=y+1;
            i++;
        }
        else{
            if(checkJanken(teste->table[x][y+1], teste->table[x][y])){
                rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
                rt[i]->origem[0]=x;
                rt[i]->origem[1]=y+1;
                rt[i]->destino[0]=x;
                rt[i]->destino[1]=y;
                i++;
            }
        }
    }    

    //right
    if((y-1)>0){
        if(checkJanken(teste->table[x][y], teste->table[x][y-1])){
            rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
            rt[i]->origem[0]=x;
            rt[i]->origem[1]=y;
            rt[i]->destino[0]=x;
            rt[i]->destino[1]=y-1;
            i++;
        } 
        else{
            if(checkJanken(teste->table[x][y-1], teste->table[x][y])){
                rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
                rt[i]->origem[0]=x;
                rt[i]->origem[1]=y-1;
                rt[i]->destino[0]=x;
                rt[i]->destino[1]=y;
                i++;
            } 
        }
    }    

    //up
    if((x-1)>0){
        if(checkJanken(teste->table[x][y], teste->table[x-1][y])){
            rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
            rt[i]->origem[0]=x;
            rt[i]->origem[1]=y;
            rt[i]->destino[0]=x-1;
            rt[i]->destino[1]=y;
            i++;
        } 
        else{
            if(checkJanken(teste->table[x-1][y], teste->table[x][y])){
                rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
                rt[i]->origem[0]=x-1;
                rt[i]->origem[1]=y;
                rt[i]->destino[0]=x;
                rt[i]->destino[1]=y;
                i++;
            } 
        }
    }    

    //down
    if((x+1)<teste->rows){
        if(checkJanken(teste->table[x][y], teste->table[x+1][y])){
            rt=(Movimento **)realloc(rt, (i+2)*sizeof(Movimento *));
            rt[i]->origem[0]=x;
            rt[i]->origem[1]=y;
            rt[i]->destino[0]=x+1;
            rt[i]->destino[1]=y;
            i++;
        } 
        else{

            if(checkJanken(teste->table[x+1][y], teste->table[x][y])){
                rt=(Movimento **)realloc(rt, (i+1)*sizeof(Movimento *));
                rt[i]->origem[0]=x+1;
                rt[i]->origem[1]=y;
                rt[i]->destino[0]=x;
                rt[i]->destino[1]=y;
                i++;
            } 
        }
    }    
    *nMoves=i;
    return rt;
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
    int nMoves=0; 
    int i;
    //caso estiver numa situação de fim.
    //A jogada completa estará no vetor caminho,
    //que será limpo na função externa a recursão.
    if(checkWin(teste->table, teste->rows, teste->columns))
        return true;

    //checar todos os movimentos possíveis!
    Movimento **assignment=checkMove(x, y, &nMoves);
    //nenhum movimento é possível desta peça
    if(assignment==NULL)
        return false;
    //p/ cada movimento possível
    for(i=0; i < nMoves; i++){
        caminho.push_back(*assignment[i]);
        if(BruteCheckR(assignment[i]->destino[0], assignment[i]->destino[1]))
            //win output here
        caminho.pop_back();
    }
    return false;
}


void BruteCheck(game *teste){
    int i, j;
    for(i=0;i<teste->rows;i++){
        for(j=0;j<teste->columns; j++)
            if(teste->table[i][j]!=EMPTY)
                BruteCheckR(i, j);
    }
}


