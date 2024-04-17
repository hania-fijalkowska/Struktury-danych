#include "ListaD.h"
void ListaD::dodaj(int pozycja, int wartosc) {
    if (head == nullptr || pozycja == 1) { // jeśli lista jest pusta lub dodajemy na początek
        auto nowyWezel = new WezelD();
        nowyWezel->dana = wartosc;
        nowyWezel->nastepny = head;
        nowyWezel->poprzedni = nullptr;
        if (head != nullptr) {
            head->poprzedni = nowyWezel;
        }
        head = nowyWezel;
        if (tail == nullptr) {
            tail = head;
        }
        rozmiar++;
    } else if (pozycja == rozmiar + 1) { // jeśli dodajemy na koniec
        auto nowyWezel = new WezelD();
        nowyWezel->dana = wartosc;
        nowyWezel->nastepny = nullptr;
        nowyWezel->poprzedni = tail;
        if (tail != nullptr) {
            tail->nastepny = nowyWezel;
        }
        tail = nowyWezel;
        if (head == nullptr) {
            head = tail;
        }
        rozmiar++;
    } else {
        auto nowyWezel = new WezelD();
        nowyWezel->dana = wartosc;
        WezelD *obecny = head;
        for (int i = 1; i < pozycja - 1; i++) {
            obecny = obecny->nastepny;
        }
        nowyWezel->nastepny = obecny->nastepny;
        nowyWezel->poprzedni = obecny;
        obecny->nastepny->poprzedni = nowyWezel;
        obecny->nastepny = nowyWezel;
        rozmiar++;
    }
}

void ListaD::usun(int pozycja) {
    if (pozycja < 1 || pozycja > rozmiar){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    if (head == nullptr){
        std::cout << "Lista jest pusta. Brak danej do usuniecia" << std::endl;
        return;
    }

    if (pozycja == 1) {
        WezelD* doUsuniecia = head;
        head = head->nastepny;
        if (head != nullptr) {
            head->poprzedni = nullptr;
        } else {
            tail = nullptr; // if the list becomes empty after deletion
        }
        delete doUsuniecia;
    } else if (pozycja == rozmiar) {
        WezelD* doUsuniecia = tail;
        tail = tail->poprzedni;
        if (tail != nullptr) {
            tail->nastepny = nullptr;
        } else {
            head = nullptr; // if the list becomes empty after deletion
        }
        delete doUsuniecia;
    } else {
        WezelD* current = head;
        for (int i = 1; i < pozycja; i++) {
            current = current->nastepny;
        }
        current->poprzedni->nastepny = current->nastepny;
        current->nastepny->poprzedni = current->poprzedni;
        delete current;
    }
    rozmiar--;
}

void ListaD::wyswietl() {
    WezelD* temp = head;
    if (head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }

    while( temp != nullptr){
        std::cout << temp->dana << " ";
        temp = temp->nastepny;
    }
}

int ListaD::podajRozmiar() {
    return rozmiar;
}

int ListaD::pobierz(int pozycja) {
    if (head == nullptr || pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return -1;
    }

    WezelD* temp = head;
    for (int i = 1; i < pozycja; i++){
        temp = temp->nastepny;
    }
    return temp->dana;
}

bool ListaD::pusta() {
    if(head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return true;
    }

    std::cout << "Lista nie jest pusta" << std::endl;
    return false;
}

bool ListaD::znajdz(int wartosc) {
    WezelD* temp = head;

    while(temp != nullptr){
        if(temp->dana == wartosc){
            return true;
        }
        temp = temp->nastepny;
    }

    return false;
}


