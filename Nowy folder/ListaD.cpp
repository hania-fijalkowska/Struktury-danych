#include "ListaD.hpp"

ListaD::~ListaD(){
    while(rozmiar!=0){
        usun(1);
    }
}

void ListaD::dodaj(int pozycja, int wartosc) {
    if (pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    WezelD *nowyWezel = new WezelD();
    nowyWezel->dana = wartosc;

    if (head == nullptr || pozycja == 1) { // jeœli lista jest pusta lub dodajemy na pocz¹tek


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
    } else if (pozycja == rozmiar + 1) { // jeœli dodajemy na koniec

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
        if(pozycja<(rozmiar/2)){

            WezelD *obecny = head;
            for (int i = 1; i < pozycja - 1; i++) {
                obecny = obecny->nastepny;
            }
            nowyWezel->nastepny = obecny->nastepny;
            nowyWezel->poprzedni = obecny;
            obecny->nastepny->poprzedni = nowyWezel;
            obecny->nastepny = nowyWezel;
            rozmiar++;
            return;

        }else{
            WezelD *obecny = tail;
            for (int i = rozmiar; i > pozycja; i--) {
                obecny = obecny->poprzedni;
            }
            nowyWezel->nastepny = obecny;
            nowyWezel->poprzedni = obecny->poprzedni;
            obecny->poprzedni->nastepny = nowyWezel;
            obecny->poprzedni = nowyWezel;
            rozmiar++;
        }
    }
}

void ListaD::usun(int pozycja) {
    if (pozycja < 1 || pozycja > rozmiar){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return;
    }

    WezelD* doUsuniecia;

    if (head == nullptr){
        std::cout << "Lista jest pusta. Brak danej do usuniecia" << std::endl;
        return;
    }

    if (pozycja == 1) {
        doUsuniecia = head;
        head = head->nastepny;
        if (head != nullptr) {
            head->poprzedni = nullptr;
        } else {
            tail = nullptr; // if the list becomes empty after deletion
        }
        delete doUsuniecia;
    } else if (pozycja == rozmiar) {
        doUsuniecia = tail;
        tail = tail->poprzedni;
        if (tail != nullptr) {
            tail->nastepny = nullptr;
        } else {
            head = nullptr; // if the list becomes empty after deletion
        }
        delete doUsuniecia;
    } else {
        if(pozycja<(rozmiar/2)){
            WezelD* current = head;
            for (int i = 1; i < pozycja; i++) {
                current = current->nastepny;
            }
            current->poprzedni->nastepny = current->nastepny;
            current->nastepny->poprzedni = current->poprzedni;
            delete current;
        } else {
            WezelD* current = tail;
            for (int i = rozmiar; i > pozycja; i--) {
                current = current->poprzedni;
            }
            current->poprzedni->nastepny = current->nastepny;
            current->nastepny->poprzedni = current->poprzedni;
            delete current;
        }
    }
    rozmiar--;
}

void ListaD::Wyswietl() {
    WezelD* temp = head;
    if (head == nullptr){
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }

    std::cout << "Lista Dwukierunkowa: \n" << "Rozmiar: " << rozmiar << std::endl;
    int i=1;
    while( temp != nullptr){
        std::cout << i++ << "\t"<< temp->dana << std::endl;
        temp = temp->nastepny;
    }
}



int ListaD::pobierz(int pozycja) {
    if (head == nullptr || pozycja < 1 || pozycja > rozmiar + 1){
        std::cout << "Niepoprawna pozycja" << std::endl;
        return -1;
    }
    WezelD* temp;
    if(pozycja<(rozmiar/2)){
        temp= head;
        for (int i = 1; i < pozycja; i++){
            temp = temp->nastepny;
        }
        return temp->dana;
    } else {
        temp = tail;
        for (int i = rozmiar; i > pozycja; i--){
            temp = temp->nastepny;
        }
        return temp->dana;
    }
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

void ListaD::WypelniPseldolosowo(int ziarno, int zakres, int ilosc){
        std::mt19937 gen(ziarno);
        std::uniform_int_distribution<> distribution(1, zakres);

        for (int i = 0; i < ilosc; ++i){
            dodaj(rozmiar+1, distribution(gen));
        }
    }


