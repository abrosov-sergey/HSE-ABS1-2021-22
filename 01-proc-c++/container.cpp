//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <iostream>

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера 
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while(!ifst.eof()) {
        if((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера 
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток 
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

//------------------------------------------------------------------------------
// Сортировка массива по заданной функции
void GetSorted(container &c) {
    for (int i = 0; i < c.len; i++) {
        for (int j = 0; j < c.len - 1; j++) {
            // std::cout << j << " " << j + 1 << std::endl;
            // std::cout << fixed << setprecision(9) << c.cont[j]->func_result << " " << c.cont[j + 1]->func_result << std::endl;

            if (c.cont[j]->func_result > c.cont[j + 1]->func_result) {
                // plants s1 = (*c.cont[j]);
                // plants s2 = (*c.cont[j + 1]);
                // (*c.cont[j]) = s2;
                // (*c.cont[j + 1]) = s1;

                plants *temp = c.cont[j];
                
                c.cont[j] = c.cont[j + 1];
                c.cont[j + 1] = temp;
            }

            //std::cout <<  fixed << setprecision(9) << c.cont[j]->func_result << " " << c.cont[j + 1]->func_result << std::endl;
        }
    }

    // for (int i = 0; i < c.len; i++) {
    //     std::cout << fixed << setprecision(9) << c.cont[i]->func_result << std::endl;
    // }
}
