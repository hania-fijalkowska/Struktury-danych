#include "Tablica.hpp"

#include <iostream>


void T_dynamiczna::ZwiekszPojemnosc(){
    int *wskPomocny = new int[2*pojemnosc];

    for(int i=0 ; i < rozmiar ; i++){

        wskPomocny[i] = lista[i];
    }

    delete []lista;
    lista = wskPomocny;
    pojemnosc*=2;
}

void T_dynamiczna::ZmniejszPojemnosc(){
    int *wskPomocny = new int[pojemnosc/2];

    for(int i=0 ; i < rozmiar ; i++){

        wskPomocny[i] = lista[i];
    }

    delete []lista;
    lista = wskPomocny;
    pojemnosc/=2;
}

void T_dynamiczna::PrzesunWPrawo(int pozycja){
    for(int i=rozmiar ; i>(pozycja-1) ; i--){
        lista[i]=lista[i-1];
    }

}

void T_dynamiczna::PrzesunWLewo(int pozycja){
    for(int i=(pozycja-1) ; i<(rozmiar-1) ; i++){
        lista[i]=lista[i+1];
    }
}

void T_dynamiczna::dodaj(int pozycja, int wartosc){
    if(rozmiar==pojemnosc){
        ZwiekszPojemnosc();
    }

    PrzesunWPrawo(pozycja);

    lista[pozycja-1]=wartosc;
    rozmiar++;

}

void T_dynamiczna::usun(int pozycja){
    if(rozmiar<((pojemnosc/2)-10)){
        ZmniejszPojemnosc();
    }

    if(pozycja<rozmiar){PrzesunWLewo(pozycja);}

    rozmiar--;
}

int T_dynamiczna::pobierz(int pozycja){
    return lista[pozycja-1];
}

bool T_dynamiczna::znajdz(int wartosc){
    bool b = false;
    for(int i=0; i<rozmiar; i++){
        if(lista[i]==wartosc){
            b = true;
            break;
        }
    }
    return b;
}


int T_dynamiczna::PodajPojemnosc(){
    return pojemnosc;
}

void T_dynamiczna::Wyswietl(){
    std::cout << "TABLICA: \n" << "Pojemnosc: " << pojemnosc << "\nRozmiar: " << rozmiar << std::endl;
    for(int i=0; i < pojemnosc; i++){
        std::cout << (i+1) << "\t";
        if(i<rozmiar){
            std::cout << pobierz(i+1) << std::endl;
        }
        else{
            std::cout << "-\n";
        }
    }
}

