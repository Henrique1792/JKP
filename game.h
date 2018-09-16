#ifndef GAME_H_
#define GAME_H_

#include <map>
#include <vector>
#include "game.h"
#include "utils.h"

//JANKEN RULES:
#define EMPTY 0
#define ROCK 1
#define SCISSORS 2
#define PAPER 3



class game{
    //Scope


    private:
        static game* instance;
        game();
    public:

        //Atributes
        std::vector<std::vector<int> > table;
        int rows, columns, possibilities;

        //Methods
        static game *getInstance();
        ~game();
        void printGame();

};

bool checkWin(std::vector<std::vector<int> > table, int row, int column);
void BruteCheck();
Movimento *checkMove(int *nMoves);
bool checkJanken(int x1, int x2);

#endif
