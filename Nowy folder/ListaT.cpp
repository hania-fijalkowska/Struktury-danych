#include <iostream>
#include "ListaT.hpp"

ListaT::~ListaT(){
    while(rozmiar!=0){
        usun(1);
    }
}

void ListaT::dodaj(int pozycja, int wartosc) {
    if (pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    auto nowyWezel = new Wezel();
    nowyWezel->dana = wartosc;

    if (head == nullptr){
        head = tail = nowyWezel;
        rozmiar++;
        return;
    }

    if (pozycja == 1){
        nowyWezel->nastepny = head;
        head = nowyWezel;
        rozmiar++;
        return;
    }

    if (pozycja == rozmiar + 1){
        nowyWezel->nastepny = nullptr;
        tail->nastepny = nowyWezel;
        tail = nowyWezel;
        rozmiar++;
        return;

    } else {
        Wezel* temp = head;
        for(int i = 1; i < pozycja - 1; i++){
            temp = temp->nastepny;
        }

        nowyWezel->nastepny = temp->nastepny;
        temp->nastepny = nowyWezel;
        if(temp == tail){
            tail = nowyWezel;
        }
        rozmiar++;
        return;
    }
}

void ListaT::usun(int pozycja) {
    if (pozycja < 1 || pozycja > rozmiar ){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    if (head == nullptr){
        std::cout << "Lista jest pusta. Brak danej do usuniecia" << std::endl;
        return;
    }

    if (pozycja == 1){
        Wezel* temp = head;
        head = head->nastepny;
        if (head == nullptr){
            tail = nullptr;
        }
        delete temp;
        rozmiar--;
        return;
    }

    Wezel* temp = head;
    Wezel* poprzedni = nullptr;
    for(int i = 1; i < pozycja; i++){
        poprzedni = temp;
        temp = temp->nastepny;
    }
    poprzedni->nastepny = temp->nastepny;
    delete temp;
    rozmiar--;
    if(poprzedni->nastepny == nullptr){
        tail = poprzedni;
    }
}

void ListaT::Wyswietl() {
    Wezel* temp = head;
    if (head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }
    std::cout << "Lista Jednokierunkowa: \n" << "Rozmiar: " << rozmiar << std::endl;
    int i=1;
    while( temp != nullptr){
        std::cout << i++ << "\t"<< temp->dana << std::endl;
        temp = temp->nastepny;

    }

}



int ListaT::pobierz(int pozycja) {
    if (head == nullptr || pozycja < 1 || pozycja > rozmiar ){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return -1;
    }
    if(pozycja==rozmiar) return tail->dana;

    Wezel* temp = head;
    for (int i = 1; i < pozycja; i++){
        temp = temp->nastepny;
    }
    return temp->dana;
}

bool ListaT::znajdz(int wartosc) {
    Wezel* temp = head;

    while(temp != nullptr){
        if(temp->dana == wartosc){
            return true;
        }
        temp = temp->nastepny;
    }

    return false;
}



void ListaT::WypelniPseldolosowo(int ziarno, int zakres, int ilosc){
        std::mt19937 gen(ziarno);
        std::uniform_int_distribution<> distribution(1, zakres);

        for (int i = 0; i < ilosc; ++i){
            dodaj(rozmiar+1, distribution(gen));
        }
    }





