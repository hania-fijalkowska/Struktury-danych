#ifndef PROJEKT1_WEZELD_HPP
#define PROJEKT1_WEZELD_HPP

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
