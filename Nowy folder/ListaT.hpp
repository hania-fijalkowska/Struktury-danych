#ifndef PROJEKT1_LISTAT_HPP
#define PROJEKT1_LISTAT_HPP

#include "Struktura.hpp"
#include "Wezel.hpp"
#include <iostream>


class ListaT : public Struktura {
private:
    Wezel* head;
    Wezel* tail;

public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);

    void Wyswietl();

    void WypelniPseldolosowo(int ziarno, int zakres, int ilosc);

    ListaT(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }
    ~ListaT();
};


#endif //PROJEKT1_LISTAT_H
