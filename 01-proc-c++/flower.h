#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - содержит описание цветка
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// цветок
struct flower {
    enum key {DOMESTIC, GARDEN, WILD}; 
    key habitat;
};

// Ввод параметров цветка из файла
void In(flower &f, ifstream &ifst);

// Случайный ввод параметров цветка
void InRnd(flower &f);

// Вывод параметров цветка в форматируемый поток
void Out(flower &f, ofstream &ofst);

#endif //__flower__
