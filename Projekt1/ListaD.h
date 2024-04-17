#ifndef PROJEKT1_LISTAD_H
#define PROJEKT1_LISTAD_H

#include "Struktura.h"
#include "WezelD.h"
#include <iostream>


class ListaD {
private:
    WezelD* head;
    WezelD* tail;
    int rozmiar;

public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);
    bool pusta();
    void wyswietl();
    int podajRozmiar();

    ListaD(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }

};


#endif //PROJEKT1_LISTAD_H
