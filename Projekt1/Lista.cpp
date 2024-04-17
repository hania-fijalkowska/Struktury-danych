#include <iostream>
#include "Lista.h"

void Lista::dodaj(int pozycja, int wartosc) {
    if (pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    auto nowyWezel = new Wezel();
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
        obecny = poprzedni->nastepny;
    }
    poprzedni->nastepny = obecny->nastepny;
    delete obecny;
    rozmiar--;
}

void Lista::wyswietl() {
    Wezel* temp = head;
    if (head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }

    while( temp != nullptr){
        std::cout << temp->dana << " ";
        temp = temp->nastepny;
    }
}

int Lista::podajRozmiar() {
    return rozmiar;
}

int Lista::pobierz(int pozycja) {
    if (head == nullptr || pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return -1;
    }

    Wezel* temp = head;
    for (int i = 1; i < pozycja; i++){
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

bool Lista::pusta() {
    if(head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return true;
    }
    std::cout << "Lista nie jest pusta" << std::endl;
    return false;
}