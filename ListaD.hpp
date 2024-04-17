#ifndef PROJEKT1_LISTAD_HPP
#define PROJEKT1_LISTAD_HPP

#include "Struktura.hpp"
#include "WezelD.hpp"
#include <iostream>


class ListaD : public Struktura{
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
    void Wyswietl();
    int podajRozmiar();

    ListaD(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }

};


#endif //PROJEKT1_LISTAD_H
