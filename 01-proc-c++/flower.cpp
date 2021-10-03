//------------------------------------------------------------------------------
// flower.cpp - содержит функции обработки цветка
//------------------------------------------------------------------------------

#include <string>

#include "flower.h"

//------------------------------------------------------------------------------
// Ввод параметров цветка из потока
void In(flower &f, ifstream &ifst) {
    std::string habitatStr;
    ifst >> habitatStr;

    if (habitatStr == "DOMESTIC") {
        f.habitat = flower::DOMESTIC;
    } else if (habitatStr == "GARDEN") {
        f.habitat = flower::GARDEN;
    } else if (habitatStr == "WILD") {
        f.habitat = flower::WILD;
    }
}

// Случайный ввод параметров цветка
void InRnd(flower &f) {
    f.habitat = flower::DOMESTIC;
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в поток
void Out(flower &f, ofstream &ofst) {
    ofst << "type = " << f.habitat;
}

