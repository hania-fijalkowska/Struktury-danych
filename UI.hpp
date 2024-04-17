#ifndef UI_HPP
#define UI_HPP
#include "Struktura.hpp"
#include <iostream>
#include <cstdlib>
#include "GrandTest.hpp"
#include "Tablica.hpp"


void menu(bool);
void StrukturyDanych(Struktura *Wsk, bool Czyczyscic);
void GrandTest();
void ZbudujZPliku(Struktura *Wsk);
void Usun(Struktura *Wsk);
void Dodaj(Struktura *Wsk);
void Znajdz(Struktura *Wsk);
void UtworzLosowo(Struktura *Wsk);
void Wyswietl(Struktura *Wsk);



#endif // UI_HPP
