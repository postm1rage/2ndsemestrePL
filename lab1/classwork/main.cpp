#include <iostream>
#include "Time.h"
using std::cout;
using std::endl;


int main()
{
    Time t;
    t.seconds = 12100;
    t.minutes=0;
    t.hours=0;

    Print(t);
    Normalize(t);
    Print(t);

    AddSeconds(t,60);
    Print(t);

    return 0;
}
