#include "Tablica.h"
#include <iostream>

void Tablica::zwiekszPojemnosc(){
    int *wskPomocny = new int[2*pojemnosc];

    for(int i=0 ; i < rozmiar ; i++){

        wskPomocny[i] = lista[i];
    }

    delete []lista;
    lista = wskPomocny;
    pojemnosc*=2;
}

void Tablica::zmniejszPojemnosc() {
    int *wskPomocny = new int[pojemnosc/2];

    for(int i=0 ; i < rozmiar ; i++){

        wskPomocny[i] = lista[i];
    }

    delete []lista;
    lista = wskPomocny;
    pojemnosc/=2;
}

void Tablica::przesunWPrawo(int pozycja){
    for(int i=rozmiar ; i>pozycja ; i--){
        lista[i]=lista[i-1];
    }
    rozmiar++;
}

void Tablica::przesunWLewo(int pozycja){
    for(int i=(pozycja-1) ; i<(rozmiar-1) ; i++){
        lista[i]=lista[i+1];
    }
    rozmiar--;
}

void Tablica::dodaj(int pozycja, int wartosc){
    if(rozmiar==pojemnosc){
        zwiekszPojemnosc();
    }

    przesunWPrawo(pozycja);

    lista[pozycja-1]=wartosc;

}

void Tablica::usun(int pozycja){
    if(rozmiar<((pojemnosc/2)-10)){
        zmniejszPojemnosc();
    }

    przesunWLewo(pozycja);
}

int Tablica::pobierz(int pozycja){
    return lista[pozycja-1];
}

bool Tablica::znajdz(int wartosc){
    bool b = false;
    for(int i=0; i<rozmiar; i++){
        if(lista[i]==wartosc){
            b = true;
            break;
        }
    }
    return b;
}

/*bool T_dynamiczna::pusta(){
    return (rozmiar==0);
}

int T_dynamiczna::PodajRozmiar(){
    return rozmiar;
}*/

int Tablica::podajPojemnosc(){
    return pojemnosc;
}

void Tablica::wyswietl(){
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

/*void T_dynamiczna::WypelniPseldolosowo(int ziarno, int zakres, int ilosc){
    std::mt19937 gen(ziarno);
    std::uniform_int_distribution<> distribution(1, zakres);

    for (int i = 0; i < ilosc; ++i) {
        dodaj(i+1, distribution(gen));
    }

}
*/
