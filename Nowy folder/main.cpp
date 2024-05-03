#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <random>
#include "Tablica.hpp"
#include "Lista.hpp"
#include "UI.hpp"
#include "GrandTest.hpp"


using namespace std;

int main() {

    //menu(true);



    vector<int> RozmiarProblemu{320,640,1280,2560}; //20,40,80,160,320,640,
    vector<int> Ziarna{2,3,5,7,11,21,23,17};
    vector<double> Wyniki;
    //Struktura *Wsk;
    vector<int> IloscKopi;//{800000,600000,500000,400000,300000,200000,100000,60000}; //500000,500000,500000,500000,200000,100000,
    //int IloscKopi = 1000;

    for(int elemet : RozmiarProblemu){
        IloscKopi.push_back(250000000/elemet);
    }
    int I=0;

    for(int rozmiar : RozmiarProblemu){
        cout << "\n\tRozmiar: " << rozmiar;
        double SumaWynikow=0;
        int NieZeroweWarianty=0;
        for(int elemet : Ziarna){
            cout << "\n\t\tZiarno: " <<elemet;
            //Wsk=new Lista;       //Typ STRUKTURY
            //Wsk->WypelniPseldolosowo(elemet,INT_MAX,rozmiar);
            Struktura **TablicaKopi = new Struktura*[IloscKopi[I]];
//---------Dla Losowych-------------------------------------
          //int Tab[IloscKopi[I]];
            //Wsk->Wyswietl();      //Test

    //----------------Kopiowanie-------------------

            for(int i=0; i<IloscKopi[I]; i++){
                TablicaKopi[i]= new T_dynamiczna;       //Typ STRUKTURY

                //for(int j=1; j<=Wsk->PodajRozmiar();j++){



                TablicaKopi[i]->WypelniPseldolosowo(elemet,INT_MAX,rozmiar);

                //}

                /*std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distribution(1, 1.25*rozmiar);
                int Losowy=distribution(gen);
                Tab[i]=Losowy;*/




                //TablicaKopi[i]->Wyswietl();     //Test
            }

    //----------------Czas-------------------



            auto Start = std::chrono::high_resolution_clock::now();


            for(int i=0; i<IloscKopi[I]; i++){
                TablicaKopi[i]->usun(rozmiar);        //BADANA OPERACJA

            }
            auto Koniec = std::chrono::high_resolution_clock::now();
            auto Okres_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(Koniec-Start).count();
            double Wynik = (Okres_ns/IloscKopi[I]);
            cout << "\n\t\t\tIlosc Kopi: " << IloscKopi[I]
            << "\tPomiar: " << Okres_ns << " ns\t"
            << "\n\t\t\tPo podzieleniu: " << Wynik;
            if(Wynik) NieZeroweWarianty++;
            SumaWynikow+=Wynik;

    //---------Testy------------------------
            /*{for(int i=1; i<4;i++){
                cout << endl << i << "\t" << Wsk->pobierz(i);
            }

            for(int i=rozmiar; i>(rozmiar-4);i--){
                cout << endl << i << "\t" << Wsk->pobierz(i);
            }

            //Wsk->Wyswietl();
            for(int i=1; i<4;i++){
                cout << endl << i << "\t" << TablicaKopi[IloscKopi-1]->pobierz(i);
            }

            for(int i=rozmiar+1; i>(rozmiar-4);i--){
                cout << endl << i << "\t" << TablicaKopi[IloscKopi-1]->pobierz(i);
            }
        }*/

    //----------------Usuwanie alokowanych obiektow-------------------

            for(int i=0; i<IloscKopi[I]; i++){
                delete TablicaKopi[i];
            }
            delete [] TablicaKopi;

            //delete Wsk;
        }
        Wyniki.push_back(SumaWynikow/NieZeroweWarianty);
        cout << "\n\tCZAS po usrednieniu: " << Wyniki[I] << " ns";
        I++;
    }

    cout << "\n\nKONCOWO: \nRozmiar:";
    I=0;
    for(int element : RozmiarProblemu){
        cout << "\n" << element;
        I++;
    }
    I=0;
    cout << "\n\nCzas:";
    for(double element : Wyniki){
        cout << "\n" << element;
        I++;
    }

    zatwierdzenie();


    return 0;
}

