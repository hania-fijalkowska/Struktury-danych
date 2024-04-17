#ifndef PROJEKT1_LISTA_H
#define PROJEKT1_LISTA_H

#include "Struktura.h"
#include "Wezel.h"
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
    void wyswietl();
    int podajRozmiar();

    Lista()
    {
        head = nullptr;
        rozmiar = 0;
    }
};
#endif //PROJEKT1_LISTA_H
