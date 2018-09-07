#ifndef UTILS_H_
#define UTILS_H_
#include <sstream>
#include <iostream>
#include <vector>

typedef struct moviment {
    int origem[2]; //x, y
    int destino[2]; //x, y
} Movimento;

std::vector<int> getLine();



#endif
