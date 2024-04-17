#ifndef PROJEKT1_STRUKTURA_H
#define PROJEKT1_STRUKTURA_H
#include <random>
#include <iostream>

class Struktura{

protected:
    int rozmiar{};

public:

    virtual void dodaj(int pozycja,int wartosc) = 0;
    virtual int pobierz(int pozycja) = 0;
    virtual void usun(int pozycja) = 0;
    virtual bool znajdz(int wartosc) = 0;
    virtual void wyswietl() = 0;

    bool pusta(){
        return (rozmiar == 0);
    }

    int PodajRozmiar(){
        return rozmiar;
    }

    void WypelniPseldolosowo(int ziarno, int zakres, int ilosc){
        std::mt19937 gen(ziarno);
        std::uniform_int_distribution<> distribution(1, zakres);

        for (int i = 0; i < ilosc; ++i){
            dodaj(i+1, distribution(gen));
        }
    }
};

#endif //PROJEKT1_STRUKTURA_H
