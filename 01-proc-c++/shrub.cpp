//------------------------------------------------------------------------------
// shrub.cpp - содержит функции обработки кустарник
//------------------------------------------------------------------------------

#include <string>

#include "shrub.h"

//------------------------------------------------------------------------------
// Ввод параметров кустарник из потока
void In(shrub &s, ifstream &ifst) {
    std::string habitatStr;
    ifst >> habitatStr;

    if (habitatStr == "JANURY") {
        s.habitat = shrub::JANUARY;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::FEBRARY;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::MARCH;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::APRIL;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::MAY;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::JUNE;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::JULY;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::AUGUST;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::SEPTEMBER;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::NOVEMBER;
    } else if (habitatStr == "JANURY") {
        s.habitat = shrub::DECEMBER;
    } 
}

// Случайный ввод параметров кустарник
void InRnd(shrub &s) {
    s.habitat = shrub::JANUARY;
}

//------------------------------------------------------------------------------
// Вывод параметров кустарник в поток
void Out(shrub &s, ofstream &ofst) {
    ofst << "type = " << s.habitat;
}
