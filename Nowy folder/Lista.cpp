#include <iostream>
#include "Lista.hpp"

Lista::~Lista(){
        while(head!=nullptr){
            usun(1);
        }
}

void Lista::dodaj(int pozycja, int wartosc) {
    if (pozycja < 1 || pozycja >rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    Wezel *nowyWezel = new Wezel();
    nowyWezel->dana = wartosc;

    if (pozycja == 1){
        nowyWezel->nastepny = head;
        head = nowyWezel;
        rozmiar++;
        return;
    } else {
        Wezel* temp = head;
        for(int i = 1; i < pozycja - 1; i++){
            temp = temp->nastepny;
        }

        nowyWezel->nastepny = temp->nastepny;
        temp->nastepny = nowyWezel;
        rozmiar++;
        return;
    }
}

void Lista::usun(int pozycja) {
    if (head == nullptr) {
        std::cout << "Lista pusta. Brak danej do usuniecia" << std::endl;
        return;
    }

    if (rozmiar < pozycja || pozycja < 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    if (pozycja == 1){
        Wezel* temp = head;
        head = head->nastepny;
        delete temp;
        rozmiar--;
        return;
    }

    Wezel* obecny = head;
    Wezel* poprzedni = nullptr;

    for (int i = 1; i < pozycja; i++){
        poprzedni = obecny;
        obecny = obecny->nastepny;
    }
    poprzedni->nastepny = obecny->nastepny;
    delete obecny;
    rozmiar--;
}

void Lista::Wyswietl() {
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



int Lista::pobierz(int pozycja) {
    if (head == nullptr || pozycja < 1 || pozycja > rozmiar ){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return -1;
    }

    Wezel* temp = head;
    for (int i = 1; i <pozycja; i++){
        temp = temp->nastepny;
    }
    return temp->dana;
}

bool Lista::znajdz(int wartosc) {
    Wezel* temp = head;

    while(temp != nullptr){
        if(temp->dana == wartosc){
            return true;
        }
        temp = temp->nastepny;
    }

    return false;
}

void Lista::WypelniPseldolosowo(int ziarno, int zakres, int ilosc){
        std::mt19937 gen(ziarno);
        std::uniform_int_distribution<> distribution(1, zakres);

        for (int i = 0; i < ilosc; ++i){
            dodaj(1, distribution(gen));
        }
    }
