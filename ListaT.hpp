#ifndef PROJEKT1_LISTAT_HPP
#define PROJEKT1_LISTAT_HPP

#include "Struktura.hpp"
#include "Wezel.hpp"
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
    void Wyswietl();
    int podajRozmiar();

    ListaT(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }
};


#endif //PROJEKT1_LISTAT_H
