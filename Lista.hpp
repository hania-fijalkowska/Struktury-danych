#ifndef PROJEKT1_LISTA_HPP
#define PROJEKT1_LISTA_HPP

#include "Struktura.hpp"
#include "Wezel.hpp"
#include <iostream>

class Lista : public Struktura {
private:
    Wezel* head;
    int rozmiar;

public:
    void dodaj(int pozycja,int wartosc);
    int pobierz(int pozycja);
    void usun(int pozycja);
    bool znajdz(int wartosc);
    bool pusta();
    void Wyswietl();
    int podajRozmiar();

    Lista()
    {
        head = nullptr;
        rozmiar = 0;
    }
    ~Lista(){}
};
#endif //PROJEKT1_LISTA_H
