#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "game.h"
#include "utils.h"

//JANKEN RULES:
#define EMPTY 0
#define ROCK 1
#define SCISSORS 2
#define PAPER 3

/*
 * JANKEN rules
 * check legal movement from x1 to x2 due to janken
 */

class game{
    //Scope


    private:
        static game* instance;
        game();
    public:

        //Atributes
        std::vector<std::vector<int>> table;
        int rows, columns, possibilities;

        //Methods
        static game *getInstance();
        ~game();
        void printGame();

};

bool checkWin(std::vector<std::vector<int>> table, int row, int column);

Movimento **checkMove(int x, int y);
bool checkJanken(int x1, int x2);

#endif
