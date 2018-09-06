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

#define CHECK_Kill(x1, x2) if((x1==SCISSORS && x2==PAPER) || (x1==PAPER && x2==ROCK) || (x1==ROCK && x2==SCISSORS)) return true; \
                                  else return false;

class game{
    //Scope
    
    
    private:
        static game* instance;
        game();
    public:

    //Atributes
    std::vector<std::vector<int>> table;
    int rows, columns;

    //Methods
    static game *getInstance();
    ~game();
    void printGame();

};

#endif
