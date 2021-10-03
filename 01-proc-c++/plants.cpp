//------------------------------------------------------------------------------
// plants.cpp - содержит процедуры связанные с обработкой обобщенного растения
// и создания произвольного растения
//------------------------------------------------------------------------------

#include <string>

#include "plants.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла
plants* In(ifstream &ifst) {
    plants *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = new plants;
            sp->k = plants::SHRUB;
            In(sp->s, ifst);
            ifst >> sp->name;
            sp->func_result = Func(sp->name);
            return sp;
        case 2:
            sp = new plants;
            sp->k = plants::TREE;
            In(sp->t, ifst);
            ifst >> sp->name;
            sp->func_result = Func(sp->name);
            return sp;
        case 3: 
            sp = new plants;
            sp->k = plants::FLOWER;
            In(sp->f, ifst);
            ifst >> sp->name;
            sp->func_result = Func(sp->name);
            return sp;

        default:
            return 0;
    }
}

// Случайный ввод обобщенного растения
plants *InRnd() {
    plants *sp;
    int k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp = new plants;
            sp->k = plants::SHRUB;
            InRnd(sp->s);
            sp->name = "shrub";
            sp->func_result = Func(sp->name);
            return sp;
        case 2:
            sp = new plants;
            sp->k = plants::TREE;
            InRnd(sp->t);
            sp->name = "tree";
            sp->func_result = Func(sp->name);
            return sp;
        case 3:
            sp = new plants;
            sp->k = plants::FLOWER;
            InRnd(sp->f);
            sp->name = "flower";
            sp->func_result = Func(sp->name);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего растения в поток
void Out(plants &s, ofstream &ofst) {
    switch(s.k) {
        case plants::SHRUB:
            Out(s.s, ofst);
            break;
        case plants::TREE:
            Out(s.t, ofst);
            break;
        case plants::FLOWER:
            Out(s.f, ofst);
            break;
        default:
            ofst << "Incorrect plants!" << endl;
    }

    ofst << ", name = " << s.name
         << ", func_result = " << fixed << setprecision(9) << s.func_result
         << "\n";
}

//------------------------------------------------------------------------------
// Вычисление частного от числа гласных букв в названии 
// на общую длину названия обобщенного растения ???
double Func(std::string a) {
    double cnt_glas = 0.0;

    char glas[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < a.length(); i++) 
    { 
        bool check = false;

        for (int j = 0; j < 6; i++) { 
            if (glas[j] == a[i]) {
                check = true;
                break;
            }
        }

        if (check) {
            cnt_glas += 1.0;
        }
    }

    return a.length() / cnt_glas;
}
