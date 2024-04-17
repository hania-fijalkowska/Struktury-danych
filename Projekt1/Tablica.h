#ifndef PROJEKT1_TABLICA_H
#define PROJEKT1_TABLICA_H

#include "Struktura.h"
#include <iostream>

class Tablica : public Struktura {
    int pojemnosc={4};
    int *lista = new int[4];

    void zwiekszPojemnosc();
    void zmniejszPojemnosc();
    void przesunWPrawo(int pozycja);
    void przesunWLewo(int pozycja);

public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);
    bool pusta();
    int podajRozmiar();
    int podajPojemnosc();
    void wyswietl();
    void wypelniPseldolosowo(int ziarno, int zakres, int ilosc);

};


#endif //PROJEKT1_TABLICA_H
