#ifndef __shrub__
#define __shrub__

//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарники
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// кустарники
struct shrub {
    enum key {JANUARY, FEBRARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER}; 
    key habitat;
};

// Ввод параметров кустарники из файла
void In(shrub &s, ifstream &ifst);

// Случайный ввод параметров кустарника
void InRnd(shrub &s);

// Вывод параметров кустарники в форматируемый поток
void Out(shrub &s, ofstream &ofst);

#endif //__shrub__
