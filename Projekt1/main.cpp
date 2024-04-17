#include <iostream>
#include "Lista.h"

int main() {
    Lista lista;

    // Testowanie dodawania na różnych pozycjach
    lista.dodaj(1, 10);  // Dodanie na początku listy
    lista.dodaj(2, 20);  // Dodanie na końcu listy
    lista.dodaj(2, 15);  // Dodanie w środku listy
    //lista.wyswietl();

    lista.dodaj(4, 30);  // Dodanie na początku listy
    lista.dodaj(2, 40);  // Dodanie na końcu list
    lista.dodaj(6, 50);  // Dodanie na początku listy
    lista.dodaj(7, 40);  // Dodanie na końcu listy
    lista.dodaj(1, 100);

    lista.wyswietl();


    lista.usun(1);  // Usunięcie elementu na pozycji 2
    /*//std::cout << lista.podajRozmiar();
    lista.usun(3);  // Usunięcie elementu na końcu*/




    std::cout << std::endl;
    lista.wyswietl();

    lista.usun(7);
    std::cout << std::endl;
    lista.wyswietl();

    lista.usun(3);
    std::cout << std::endl;
    lista.wyswietl();

    return 0;
}
