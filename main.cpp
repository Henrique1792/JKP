#include "utils.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
    std::vector<int>line=getLine();
    for(std::vector<int>::iterator p=line.begin(); p!=line.end(); p++)
        cout << *p << " ";
    return 0;
}
