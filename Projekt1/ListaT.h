#ifndef PROJEKT1_LISTAT_H
#define PROJEKT1_LISTAT_H

#include "Struktura.h"
#include "Wezel.h"
#include <iostream>


class ListaT : public Struktura {
private:
    Wezel* head;
    Wezel* tail;
    int rozmiar;

public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);
    bool pusta();
    void wyswietl();
    int podajRozmiar();

    ListaT(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }
};


#endif //PROJEKT1_LISTAT_H
