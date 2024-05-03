#ifndef PROJEKT1_WEZEL_HPP
#define PROJEKT1_WEZEL_HPP

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
