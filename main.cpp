#include "utils.h"
#include "game.h"

using namespace std;

std::vector<Movimento>caminho;
std::map<int, Movimento> estadoF;
game *teste;

int main(int argc, char *argv[]){
    teste=game::getInstance();
    BruteCheck();
    std::multimap<int, Movimento>::iterator iter;

    for(iter=estadoF.begin(); iter!=estadoF.end(); iter++){
        printf("%d \n", iter->first);
        printf("%d %d %d\n", iter->second.origem[0],
                             iter->second.origem[1],
                             iter->second.jankenP);
    }

    return 0;
}
