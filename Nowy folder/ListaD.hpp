#ifndef PROJEKT1_LISTAD_HPP
#define PROJEKT1_LISTAD_HPP

#include "Struktura.hpp"
#include "WezelD.hpp"
#include <iostream>


class ListaD : public Struktura{
private:
    WezelD* head;
    WezelD* tail;


public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);

    void Wyswietl();

    void WypelniPseldolosowo(int ziarno, int zakres, int ilosc);


    ListaD(){
        head = nullptr;
        tail = nullptr;
        rozmiar = 0;
    }
    ~ListaD();

};


#endif //PROJEKT1_LISTAD_H
