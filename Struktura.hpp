#ifndef STRUKTURA_HPP
#define STRUKTURA_HPP
#include <random>
#include <iostream>
#include <climits>
#include <fstream>
#include <string>

class Struktura{

protected:
    int rozmiar{};

public:


    virtual ~Struktura(){}

    virtual void dodaj(int pozycja,int wartosc)=0;
    virtual int pobierz(int pozycja)=0;
    virtual void usun(int pozycja)=0;
    virtual bool znajdz(int wartosc)=0;

    virtual void Wyswietl()=0;

    bool pusta(){
        return (rozmiar==0);
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

    void WypelniPseldolosowo(int zakres, int ilosc){
        rozmiar=0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution(1, zakres);

        for (int i = 0; i < ilosc; ++i){
            dodaj(i+1, distribution(gen));
        }
    }
};


#endif
