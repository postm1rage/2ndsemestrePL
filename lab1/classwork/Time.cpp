#include "Time.h"
#include <iostream>

using namespace std;

void Normalize(Time& t){
    t.minutes += t.seconds / 60;
    t.seconds %= 60;

    if (t.seconds < 0)
    {
        t.minutes -= 1;
        t.seconds += 60;
    }

    t.hours += t.minutes / 60;
    t.minutes %= 60;

    if (t.minutes < 0)
    {
        t.hours -= 1;
        t.minutes += 60;
    }

    t.hours %= 24;

    if (t.hours < 0)
    {
        t.hours += 24;
    }
}

void AddSeconds(Time t,int s){
    t.seconds += s;
    Normalize(t);
}

void Print(Time t){
    cout<<t.hours<<" : "<<t.minutes<<" : "<<t.seconds<<endl;
}
