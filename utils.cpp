#include "utils.h"


std::vector<int> getLine(){

    int n;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::vector<int> rt;

    while(true) {
        stream >> n;
        rt.push_back(n);
        if(!stream)
            break;
    }
    return rt;
}



Movimento *newMovimento(){
    Movimento *rt=(Movimento *)malloc(sizeof(Movimento));
    return rt;
}


void freeMovimento(Movimento *tgt){
    free(tgt);
}
