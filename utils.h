#ifndef UTILS_H_
#define UTILS_H_
#include <sstream>
#include <iostream>
#include <vector>

typedef struct Movimento {
    int origem[2]; //x, y
    int destino[2]; //x, y
    int jankenO;
    int jankenP;
} Movimento;

std::vector<int> getLine();
Movimento *newMovimento();
void freeMovimento(Movimento *tgt);
#endif
