#include "game.h"

//using namespace std;

game* game::instance=0;
extern game *teste;
extern std::vector<Movimento>caminho;
extern std::multimap<int, Movimento> estadoF;
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


Movimento *checkMove(int *nMoves){
    Movimento *rt=NULL;    // vetor
    int i, j, Moves=0;
    //Check each possible move
    for(i=0;i<teste->rows; i++){
        for(j=0; j<teste->columns; j++){
            //printf("peça sendo testada: %d, %d\n", i, j);
            if(teste->table[i][j]==EMPTY) continue;
            //left
            if((j+1)<teste->columns){
                if(checkJanken(teste->table[i][j], teste->table[i][j+1])){
                    rt=(Movimento *)realloc(rt, (Moves+1)*sizeof(Movimento ));
                    rt[Moves].origem[0]=i;
                    rt[Moves].origem[1]=j;
                    rt[Moves].destino[0]=i;
                    rt[Moves].destino[1]=j+1;
                    rt[Moves].jankenO=teste->table[i][j];
                    rt[Moves].jankenP=teste->table[i][j+1];
                    Moves++;
                }
            }    
            //right
            if((j-1)>0){
                if(checkJanken(teste->table[i][j], teste->table[i][j-1])){
                    rt=(Movimento *)realloc(rt, (Moves+1)*sizeof(Movimento ));
                    rt[Moves].origem[0]=i;
                    rt[Moves].origem[1]=j;
                    rt[Moves].destino[0]=i;
                    rt[Moves].destino[1]=j-1;
                    rt[Moves].jankenO=teste->table[i][j];
                    rt[Moves].jankenP=teste->table[i][j-1];
                    Moves++;
                } 
            }    

            //up
            if((i)>0){
                if(checkJanken(teste->table[i][j], teste->table[i-1][j])){
                    rt=(Movimento *)realloc(rt, (Moves+1)*sizeof(Movimento));
                    rt[Moves].origem[0]=i;
                    rt[Moves].origem[1]=j;
                    rt[Moves].destino[0]=i - 1;
                    rt[Moves].destino[1]=j;
                    rt[Moves].jankenO=teste->table[i][j];
                    rt[Moves].jankenP=teste->table[i - 1][j];
                    Moves++;
                } 
            }    

            //down
            if((i+1)<teste->rows){
                if(checkJanken(teste->table[i][j], teste->table[i+1][j])){
                    rt=(Movimento *)realloc(rt, (Moves+1)*sizeof(Movimento ));
                    rt[Moves].origem[0]=i;
                    rt[Moves].origem[1]=j;
                    rt[Moves].destino[0]=i+1;
                    rt[Moves].destino[1]=j;
                    rt[Moves].jankenO=teste->table[i][j];
                    rt[Moves].jankenP=teste->table[i+1][j];
                    Moves++;
                } 
            }
        }
    }
    *nMoves=Moves;
    return rt;
}


bool checkWin(std::vector<std::vector<int> > table, int row, int column){
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
    if( ( x1!=EMPTY && x2!=EMPTY ) &&
            (   (x1==SCISSORS && x2==PAPER) || 
                (x1==PAPER && x2==ROCK) ||
                (x1==ROCK && x2==SCISSORS)
            )
    )
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
    Movimento *assignment=checkMove(&nMoves);
    
    /*for(i=0; i <nMoves; i++)
        printf("Origem: %d %d %d \t Destino %d %d %d \n", assignment[i].origem[0],assignment[i].origem[1], assignment[i].jankenO
                                                        , assignment[i].destino[0],assignment[i].destino[1], assignment[i].jankenP); */
    
    //nenhum movimento é possível desta peça
    if(assignment==NULL)
        return false;
    //p/ cada movimento possível
    for(i=0; i < nMoves; i++){
        caminho.push_back(assignment[i]);
        teste->table[(assignment[i]).origem[0]][(assignment[i]).origem[1]]=teste->table[(assignment[i]).destino[0]][(assignment[i]).destino[1]];      
        teste->table[(assignment[i]).origem[0]][(assignment[i]).origem[1]]=EMPTY;
            if(BruteCheckR(assignment[i].destino[0], assignment[i].destino[1])){
            //estado final distinto aqui
            estadoF.insert(std::make_pair(assignment[i].jankenO, assignment[i]));
        }
        teste->table[(assignment[i]).origem[0]][(assignment[i]).origem[1]]=assignment[i].jankenO;
        teste->table[(assignment[i]).destino[0]][(assignment[i]).destino[1]]=assignment[i].jankenP;      
        caminho.pop_back();
    }
    //para evitar vazamento de memória:
    freeMovimento(assignment);
    return false;
}


void BruteCheck(){
    int i, j;
    for(i=0;i<teste->rows;i++){
        for(j=0;j<teste->columns; j++)
            if(teste->table[i][j]!=EMPTY)
                BruteCheckR(i, j);
    }
}


