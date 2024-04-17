#ifndef TABLICA_HPP
#define TABLICA_HPP
#include <iostream>
#include "Struktura.hpp"

class T_dynamiczna : public Struktura {



    int pojemnosc;
    int *lista;

    void ZwiekszPojemnosc();
    void ZmniejszPojemnosc();
    void PrzesunWPrawo(int pozycja);
    void PrzesunWLewo(int pozycja);

public:

    T_dynamiczna(){
        pojemnosc=4;
        lista = new int[4];
    }



    ~T_dynamiczna(){
        delete lista;
    }

    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);
    bool pusta();
    int PodajRozmiar();
    int PodajPojemnosc();
    void Wyswietl();


};
#endif
