#include "utils.h"
#include "game.h"

using namespace std;

std::vector<Movimento>caminho;
std::map<int, Movimento> estadoF;
game *teste;

int main(int argc, char *argv[]){
    teste=game::getInstance();
    BruteCheck();
    std::map<int, Movimento>::iterator iter;
    cout << "MapSize: "<< estadoF.size() << endl;
    for(iter=estadoF.begin(); iter!=estadoF.end(); iter++){
        printf("%d \n", iter->first);
        printf("%d %d %d\n", iter->second.destino[0],
                             iter->second.destino[1],
                             iter->second.jankenO);
    }

    return 0;
}
