#ifndef PROJEKT1_WEZEL_H
#define PROJEKT1_WEZEL_H

class Wezel{
public:
    int dana;
    Wezel* nastepny;

    Wezel(){
        dana = 0;
        nastepny = nullptr;
    }
};

#endif //PROJEKT1_WEZEL_H
