#include "UI.hpp"
using namespace std;



void Usun(Struktura *Wsk){
    int pozycja;
    int rozmiar;
    rozmiar=(Wsk->PodajRozmiar());
    cout << "\n\tPodaj pozycje od 1 do " << rozmiar << ": ";
    cin >> pozycja;
    if((pozycja<1)||(pozycja>rozmiar)){
        cout << "\n\tNiepoprawna wartosc pozycji!";
        zatwierdzenie();
    }
    else{Wsk->usun(pozycja);}
}

void Dodaj(Struktura *Wsk){
    int pozycja, wartosc;
    int rozmiar=Wsk->PodajRozmiar();
    cout << "\n\tPodaj pozycje od 1 do " << (rozmiar+1) << ": ";
    cin >> pozycja;
    cout << "\n\tPodaj wartosc od " << INT_MIN << " do " << INT_MAX << ": ";
    cin >> wartosc;
    if((pozycja<1)||(pozycja>(rozmiar+1))){
        cout << "\n\tNiepoprawna wartosc pozycji!";
        zatwierdzenie();
    }
    else{Wsk->dodaj(pozycja,wartosc);}
}

void Znajdz(Struktura *Wsk){
    int wartosc;
    cout << "\n\tPodaj wartosc od " << INT_MIN << " do " << INT_MAX << ": ";
    cin >> wartosc;
    if(Wsk->znajdz(wartosc)){
        cout << "\n\tZnaleziono liczbe " << wartosc << " w strukturze.";
    }
    else{cout << "\n\tNie znaleziono liczby " << wartosc << " w strukturze.";}

    zatwierdzenie();

}

void UtworzLosowo(Struktura *Wsk){
    int zakres, ilosc;

    cout << "\n\tPodaj maksymalna wartosc do wylosowania, nie wieksza niz " << INT_MAX << ": ";
    cin >> zakres;
    cout << "\n\tPodaj ilosc elementow do wylosowania: ";
    cin >> ilosc;
    Wsk->WypelniPseldolosowo(zakres, ilosc);

}

void ZbudujZPliku(Struktura *Wsk){
    string NazwaPliku;
    cout << "\n\tPodaj nazwe pliku: ";
    cin >> NazwaPliku;

    ifstream Plik(NazwaPliku);
    if(!Plik.is_open()){
        cout << "\n\tNie mozna otworzyc pliku";
        zatwierdzenie();
        return;
    }
    int wiersz{};
    int liczba;

    while(Plik >> liczba){
        wiersz++;
        Wsk->dodaj(wiersz,liczba);
    }

    Plik.close();

}

void Wyswietl(Struktura *Wsk){
    Wsk->Wyswietl();
    zatwierdzenie();
}





void StrukturyDanych(Struktura *Wsk, bool Czyczyscic){
    bool zapentlenie=true;
    int WyborDzialania{};
    constexpr int zbudujzpliku=1, utworzlosowo=2, dodaj=3, usun=4, znajdz=5,
    wysietl=6, powrot=7;

    while(zapentlenie){
        wyczysc(Czyczyscic);

        cout
        << "\n\tPanel wyboru pracy ze struktura:\n"
        << "\t\t1. Zbuduj z Pliku\n"
        << "\t\t2. Utworz losowo\n"
        << "\t\t3. Dodaj\n"
        << "\t\t4. Usun\n"
        << "\t\t5. Znajdz\n"
        << "\t\t6. Wyswietl\n"
        << "\t\t7. Powrot\n\n"
        << "\tPodaj nr wyboru: ";

        cin >> WyborDzialania;

        wyczysc(Czyczyscic);

        switch(WyborDzialania){
            case zbudujzpliku:
                ZbudujZPliku(Wsk);
                break;

            case utworzlosowo:
                UtworzLosowo(Wsk);
                break;

            case dodaj:
                Dodaj(Wsk);
                break;

            case usun:
                Usun(Wsk);
                break;

            case znajdz:
                Znajdz(Wsk);
                break;

            case wysietl:
                Wyswietl(Wsk);
                break;

            case powrot:
                zapentlenie=false;
                break;

            default:
                cout
                << "\nNieprawidlowa wartosc\n"
                << "Sprubuj ponownie naciskajac Enter:";
                cin.get();
                cin.get();
                break;

        }
    }
}


void menu(bool Czyczyscic){
    bool zapentlenie=true;
    constexpr int Struktury=1, GRANDTEST=2, Koniec=3;
    constexpr int TablicaDynamiczna=1, ListaJedenHEAD=2, ListaJedenTAIL=3, ListaDwa=4;
    Struktura *wsk{};

    while(zapentlenie){
        wyczysc(Czyczyscic);

        int Wybor{};
        int WyborStruktury{};
        bool ZatwierdzenieStruktury=true;


        cout
        << "\n\tMENU:\n\n"
        << "\t\t1. Sruktury\n"
        << "\t\t2. GRANDTEST\n"
        << "\t\t3. Koniec\n\n"
        << "\tPodaj nr wyboru: ";

        cin >> Wybor;

        switch(Wybor){
            case Struktury:
                wyczysc(Czyczyscic);
                cout
                << "\n\tSTRUKTURY:\n\n"
                << "\t\t1. Tablica dynamiczna\n"
                << "\t\t   Lista jednokierunkowa z:\n"
                << "\t\t\t2. HEAD\n"
                << "\t\t\t3. HEAD i TAIL\n"
                << "\t\t4. Lista dwukierunkowa\n\n"
                << "\tPodaj nr wybranej struktury: ";

                cin >> WyborStruktury;

                switch(WyborStruktury){
                    case TablicaDynamiczna:
                        wsk = new T_dynamiczna();
                        break;
                    case ListaJedenHEAD:
                        wsk = new Lista;
                        break;

                    case ListaJedenTAIL:
                        wsk = new ListaT;
                        break;

                    case ListaDwa:
                        wsk = new ListaD;
                        break;

                    default:
                        wyczysc(Czyczyscic);
                        cout
                        << "\nNieprawidlowa wartosc\n"
                        << "Sprubuj ponownie naciskajac Enter:";
                        ZatwierdzenieStruktury=false;
                        cin.get();
                        cin.get();
                        break;
                }

                if(ZatwierdzenieStruktury){StrukturyDanych(wsk,Czyczyscic);}

                delete wsk;
                break;

            case GRANDTEST:
                GrandTest();
                break;

            case Koniec:
                zapentlenie=false;
                wyczysc(Czyczyscic);
                cout << "\nDziekujemy za korzystanie z naszego programu!\n";
                break;

            default:
                wyczysc(Czyczyscic);
                cout
                << "\nNieprawidlowa wartosc\n"
                << "Sprubuj ponownie naciskajac Enter:";
                cin.get();
                cin.get();
                break;

        }
    }
}


