#ifndef PROJEKT1_WEZELD_H
#define PROJEKT1_WEZELD_H

class WezelD{
public:
    int dana;
    WezelD* nastepny;
    WezelD* poprzedni;

    WezelD(){
        nastepny = nullptr;
        poprzedni = nullptr;
        dana = 0;
    }
};

#endif //PROJEKT1_WEZELD_H
