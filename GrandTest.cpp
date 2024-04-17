#include "GrandTest.hpp"
using namespace std;

double PomiarDodawania(Struktura **wTab, int ilosc, int pozycja){
    double Start, Koniec;
    int wartosc=INT_MAX;

    Start = clock();
    for(int i=0; i<ilosc; i++){
        wTab[i]->dodaj(pozycja,wartosc);
    }
    Koniec = (clock() - Start);

    return Koniec;
}

double PomiarUsuwania(Struktura **wTab, int ilosc, int pozycja){
    double Start, Koniec;

    Start = clock();
    for(int i=0; i<ilosc; i++){
        wTab[i]->usun(pozycja);
    }
    Koniec = (clock() - Start);

    return Koniec;
}

template<typename T>
Struktura **KopieStruktury(Struktura *Wsk, int ilosc){

    Struktura **TablicaKopi = new Struktura*[ilosc];
    for(int i=0; i<ilosc; i++){
        TablicaKopi[i]= new T;

        for(int j=1; j<=Wsk->PodajRozmiar();j++){

            int tym = Wsk->pobierz(j);

            TablicaKopi[i]->dodaj(j,tym);

        }
    }

    return TablicaKopi;
}

template<typename D>
vector<double> OperacjaDodawania(Struktura *Wsk, int MaxRozmiar){
    vector<double> CzasyDodawan;//W tym wektorze zapiszemy ju¿ uœrednione wyniki dla kokretnych operacji dodawania

    int ilosc{};
    int rozmiar=Wsk->PodajRozmiar();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(1, rozmiar);
    int Losowy=distribution(gen);

    vector<int>Pozycje{1,(rozmiar+1),Losowy};


    ilosc=100;
    //((static_cast<int>(MaxRozmiar/rozmiar))+50);
    Struktura **TablicaKopi{};

    for(int element : Pozycje){
        TablicaKopi=(KopieStruktury<D>(Wsk,ilosc));//przypisanie do wektora adresu tablicy z kopiami o odpowiednim typie struktury.
        double SumaCzas;
        SumaCzas=PomiarDodawania(TablicaKopi,ilosc,element);
        for(int i=0; i<ilosc; i++){
            delete TablicaKopi[i];
        }
        delete [] TablicaKopi;
        CzasyDodawan.push_back(SumaCzas/ilosc);
    }

    return CzasyDodawan;
}

template<typename C>
vector<double> OperacjaOdejmowania(Struktura *Wsk, int MaxRozmiar){
    vector<double> CzasyUsuwania;//W tym wektorze zapiszemy ju¿ uœrednione wyniki dla kokretnych operacji dodawania

    int ilosc{};
    int rozmiar=Wsk->PodajRozmiar();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(1, rozmiar);
    int Losowy=distribution(gen);


    vector<int>Pozycje{1,rozmiar,Losowy};



    ilosc=100;
    //((static_cast<int>(MaxRozmiar/rozmiar))+50);
    Struktura **TablicaKopi{};

    for(int element : Pozycje){
        TablicaKopi=(KopieStruktury<C>(Wsk,ilosc));//przypisanie do wektora adresu tablicy z kopiami o odpowiednim typie struktury.
        double SumaCzas;
        SumaCzas=PomiarUsuwania(TablicaKopi,ilosc,element);
        for(int i=0; i<ilosc; i++){
            delete TablicaKopi[i];
        }
        delete [] TablicaKopi;
        CzasyUsuwania.push_back(SumaCzas/ilosc);
    }

    return CzasyUsuwania;
}

template<typename E>
double OperacjaWyszukiwania(Struktura *Wsk, int MaxRozmiar){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(1, INT_MAX);
    int Losowy=distribution(gen);
    int ilosc=200;

    Struktura **TablicaKopi{};
    TablicaKopi=(KopieStruktury<E>(Wsk,ilosc));

    double Start, Koniec;

    Start = clock();
    for(int i=0; i<ilosc; i++){
        TablicaKopi[i]->znajdz(Losowy);
    }
    Koniec = (clock() - Start)/ilosc;

    delete [] TablicaKopi;

    return Koniec;
}

void LaczenieZawartosci(vector<double> &Pierwotny,vector<double> &Dodawany){
    for(double element : Dodawany){
        Pierwotny.push_back(element);
    }
}

void SumowanieElementow(vector<double> &Suma,vector<double> &Pomiar){
    int N{};
    for(double & element : Suma){
        element+=Pomiar[N];
        N++;
    }
}

template<typename F>
void Wariant(Struktura *Wsk, std::vector<double> &SumyCzasow,int rozmiar, int ziarno, int MaxRozmiar){
    Wsk = new F;
    Wsk->WypelniPseldolosowo(ziarno,INT_MAX,rozmiar);
    vector<double> WynikiWariantu; //Inicjalizacja pusta, zape³niany w ciagu dzialania

    vector<double> Dodawanie=OperacjaDodawania<F>(Wsk, MaxRozmiar); //wektor przechowujacy wyniki dodawania danego wariatu
    LaczenieZawartosci(WynikiWariantu,Dodawanie);//Zapisujemmy w wektorze wyniku ca³ego wariatu

    vector<double> Usuwanie=OperacjaOdejmowania<F>(Wsk, MaxRozmiar);
    LaczenieZawartosci(WynikiWariantu,Usuwanie); //Zapisanie kolejnych 3 wartosci Usuwania

    WynikiWariantu.push_back(OperacjaWyszukiwania<F>(Wsk, MaxRozmiar));//Zapisanie wyniku Wyszukani, teraz mamy 7 elementow w wektorze

    SumowanieElementow(SumyCzasow,WynikiWariantu);//dodajemy wyniki do konkretnych pozycji wektora sumujacego czasy wariantow
                                                  //Pod koniec bedziemy mieli sume z ka¿dego wariantu dla danej populacji
    delete Wsk;
}

void PodzielElemety(std::vector<double> &wektor, int dzielnik){
    for(double & element : wektor){
        element/=dzielnik;
    }
}

template<typename G>
vector<double> PunktPomiarowy(Struktura *Wsk, std::vector<int> ziarna, int rozmiar, int MaxRozmiar){
    vector<double> SumyCzasow(7); //Inicjalizacja musi byæ 7-elementowa by nie wystompi³ b³ad w fukcjach sumujacych elemety
    int dzielnik=ziarna.size(); //wyciagamy liczbe wariantow

    for(int element: ziarna){
        Wariant<G>(Wsk,SumyCzasow,rozmiar,element,MaxRozmiar);//Dzialamy na kolejnych wariantach, wynik jest suma czaow dla kazdego.
    }


    PodzielElemety(SumyCzasow,dzielnik);//Dzielimy czasy przez liczbe wariantuw.

    return SumyCzasow;//zwracamy wektor kolejnych warosci dla danej wielkosci problemu.

}

void PentlaDlaString(std::vector<std::string> &OpisBadaniaStruktury, std::vector<int> rozmairy,double tab[][7], int rozmiar, int &I){
    string Roboczy;
    for(int i=0; i<rozmiar;i++){
        ostringstream strumien;
        strumien << " \t" << rozmairy[i] << "\t" << tab[i][I];
        OpisBadaniaStruktury.push_back(strumien.str());
    }
    I++;
}

void Formatowanie(std::vector<std::string> &OpisBadaniaStruktury, std::vector<int> rozmairy, double tab[][7], int rozmiar){
    int I=0;
    OpisBadaniaStruktury.push_back("Dodawanie\t \t \n \tPoczatek\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t \n \tKoniec\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t \n \tLosowe\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t ");
    OpisBadaniaStruktury.push_back("Usuwanie\t \t \n \tPoczatek\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t \n \tKoniec\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t \n \tLosowe\t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t ");
    OpisBadaniaStruktury.push_back("Wyszukiwanie\t \t \n \trozmiar\tczas");
    PentlaDlaString(OpisBadaniaStruktury,rozmairy,tab,rozmiar,I);
    OpisBadaniaStruktury.push_back(" \t \t ");
}

template<typename H>
std::vector<std::string> TestStruktura(Struktura *Wsk, std::vector<int> rozmairy, std::vector<int> ziarna){
    int MaxRozmiar = rozmairy[rozmairy.size()-1];
    int LiczbaPuktowPomiarowych=rozmairy.size();
    double Tab[LiczbaPuktowPomiarowych][7]{};
    int N{};

    for(int element : rozmairy){
        vector<double> Skrytka;
        Skrytka=PunktPomiarowy<H>(Wsk,ziarna,element,MaxRozmiar);
        for(int i=0; i<7; i++){
            Tab[N][i]=Skrytka[i];
        }
        N++;
    }
    vector<string> OpisBadaniaStruktury;

    Formatowanie(OpisBadaniaStruktury,rozmairy,Tab,LiczbaPuktowPomiarowych);

    return OpisBadaniaStruktury;

}

void GrandTest(){
    char TypCiagu;
    int LiczbaPuktow, WyrazPoczatkowy, Czynnik;
    int LiczbaWariantow;
    vector<int> ziarna;
    vector<int> rozmiary;
    bool potwierdz1=true;
    bool potwierdz2=false;

    while(potwierdz1){
        rozmiary.clear();
        while(true){

            cout << "\n\tPodaj Typ Ciagu A-arytmetyczny G-geometryczny: ";
            cin >> TypCiagu;
            if((TypCiagu=='A')||(TypCiagu=='G')){
                break;
            }
            cout << "Niepoprawny typ!!!\n";
        }

        cout << "\n\tPodaj Liczbe puktuw pomiarowych: ";
        cin >> LiczbaPuktow;
        cout << "\n\tPodaj wyraz poczatkowy ciagu: ";
        cin >> WyrazPoczatkowy;
        cout << "\n\tPodaj czynik dla odpowiedniego ciagu: ";
        cin >> Czynnik;



        if(TypCiagu=='A'){
            for(int i=0; i<LiczbaPuktow; i++){
                rozmiary.push_back(WyrazPoczatkowy+(i*Czynnik));
            }
        }
        else{
            for(int i=0; i<LiczbaPuktow; i++){
                rozmiary.push_back(WyrazPoczatkowy*(pow(Czynnik,i)));
            }
        }

        cout << "\n\tTwoj ciag:\n";

        for(int elemet : rozmiary){
            cout << elemet << endl;
        }

        cout
        << "\n\tCzy zatwierdzasz wybur?"
        << "\n1. tak"
        << "\n2. nie"
        << "\n3. wyjdz"
        << "\nWybierz numer: ";

        int wybor;
        cin >> wybor;

        switch(wybor){
            case 1:
                cout << "\n\tZatwierdzono.";
                potwierdz1=false;
                break;
            case 2:
                cout << "Sprubuj ponownie.";
                break;

            case 3:
                potwierdz1=false;
                potwierdz2=true;
                break;
            default:
                cout << "Niepoprawny wybur";
                break;
        }

    }

    if(potwierdz2){
        cout << "\n\tWychodzisz.";
        return;
    }

    //wyczysc(1);

    cout << "\n\tPodaj liczbe wariantow: ";
    cin >> LiczbaWariantow;
    cout << endl;

    for(int i=0; i<LiczbaWariantow; i++){
        int robocza=0;
        cout << "\n\tPodaj ziarno nr " << (i+1) << ": ";
        cin >> robocza;
        ziarna.push_back(robocza);
    }

    cout << "\n\n\tPrzechodzimy do Oblicen. Powodzenia.\n";

    ostringstream strumien;

    Struktura *Wsk;
    vector<string> Tablica=TestStruktura<T_dynamiczna>(Wsk,rozmiary,ziarna);


    cout << "\n\tTablica\n";
    strumien << "Kolumna1\tKolumna2\tKolumna3\n" << " \tTablica\t \n";

    for(auto wiersz : Tablica){
        cout << wiersz << endl;
        strumien << wiersz << "\n";
    }

    /*Wsk=new Lista;
    vector<string> Lista1=TestStruktura<Lista>(Wsk,rozmiary,ziarna);
    delete Wsk;

    cout << "\n\tLista Jednokierunkowa\n";
    strumien << "\n \tLista Jednokierunkowa\t \n";

    for(auto wiersz : Lista1){
        cout << wiersz << endl;
        strumien << wiersz << "\n";
    }

    Wsk=new ListaT;
    vector<string> Lista2=TestStruktura<ListaT>(Wsk,rozmiary,ziarna);
    delete Wsk;

    cout << "\n\tLista Jednokierunkowa TAIL\n";
    strumien << "\n \tLista Jednokierunkowa TAIL\t \n";

    for(auto wiersz : Lista2){
        cout << wiersz << endl;
        strumien << wiersz << "\n";
    }

    Wsk=new ListaD;
    vector<string> Lista3=TestStruktura<ListaD>(Wsk,rozmiary,ziarna);
    delete Wsk;

    cout << "\n\tLista Dwukierunkowa\n";
    strumien << "\n \tLista Dwukierunkowa\t \n";

    for(auto wiersz : Lista3){
        cout << wiersz << endl;
        strumien << wiersz << "\n";
    }*/

    string dane=strumien.str();
    ofstream plik("dane.csv");

    if (!plik.is_open()) {
        cout << "\n\tNie mozna otworzyc pliku do zapisu." << std::endl;
    }
    else{
        plik << dane;
        plik.close();
    }

    cout << "\n\tKoniec!!!";

    zatwierdzenie();



}

void wyczysc(bool a){
    if(a){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

    }
}

void zatwierdzenie(){
    cout << "\n\tNacisni Enter by kontynuowac.";
    cin.get();
    cin.get();
}
