#include <iostream>
#include "ListaT.hpp"

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
    if (pozycja < 1 || pozycja > rozmiar + 1){
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
        delete temp;
        rozmiar--;

        if (head == nullptr){
            tail = nullptr;
        }
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

    while( temp != nullptr){
        std::cout << temp->dana << " ";
        temp = temp->nastepny;
    }
}

int ListaT::podajRozmiar() {
    return rozmiar;
}

int ListaT::pobierz(int pozycja) {
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

bool ListaT::pusta() {
    if(head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return true;
    }

    std::cout << "Lista nie jest pusta" << std::endl;
    return false;
}






