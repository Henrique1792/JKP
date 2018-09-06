#include "utils.h"
#include "game.h"

using namespace std;


int main(int argc, char *argv[]){
    game *teste=game::getInstance();
    teste->printGame();
    return 0;
}
