#ifndef GRANDTEST_HPP
#define GRANDTEST_HPP
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "Struktura.hpp"
#include "Tablica.hpp"
#include "Lista.hpp"
#include "ListaT.hpp"
#include "ListaD.hpp"


void PodzielElemety(std::vector<double> &wektor, int dzielnik);
void LaczenieZawartosci(std::vector<double> &Pierwotny,std::vector<double> &Dodawany);
void SumowanieElementow(std::vector<double> &Suma,std::vector<double> &Pomiar);
double PomiarDodawania(Struktura **wTab, int ilosc, int pozycja);
double PomiarUsuwania(Struktura **wTab, int ilosc, int pozycja);
std::vector<double> OperacjaDodawania(Struktura *Wsk, int MaxRozmiar);
std::vector<double> OperacjaOdejmowania(Struktura *Wsk, int MaxRozmiar);
double OperacjaWyszukiwania(Struktura *Wsk, int MaxRozmiar);
Struktura **KopieStruktury(Struktura *Wsk, int ilosc);
void Wariant(Struktura *Wsk, std::vector<double> &SumyCzasow,int rozmiar, int ziarno, int MaxRozmiar);
std::vector<double> PunktPomiarowy(Struktura *Wsk, std::vector<int> ziarna, int rozmiar, int MaxRozmiar);
std::vector<std::string> TestStruktura(Struktura *Wsk, std::vector<int> rozmairy, std::vector<int> ziarna);
void PentlaDlaString(std::vector<std::string> &OpisBadaniaStruktury, std::vector<int> rozmairy, double tab[][7], int rozmiar, int &I);
void Formatowanie(std::vector<std::string> &OpisBadaniaStruktury, std::vector<int> rozmairy, double tab[][7], int rozmiar);
void GrandTest();
void wyczysc(bool a);
void zatwierdzenie();

#endif // GRANDTEST_HPP
