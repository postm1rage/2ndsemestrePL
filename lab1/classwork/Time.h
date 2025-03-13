#ifndef TIME_H
#define TIME_H

struct Time{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
};

void Normalize(Time& t);

void AddSeconds(Time t,int s);

void Print(Time t);

#endif //TIME_H