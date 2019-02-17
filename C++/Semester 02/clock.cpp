// Utility functions, interface

#include <iostream>

using namespace std;

class Clock
{
  private: // Access Specifier
    int hour, min, sec;

    void incSec()
    {
        if (sec < 59)
            sec++;

        else
        {
            sec = 0;
            incMin();
        }
    }
    void incMin()
    {
        if (min < 59)
            min++;

        else
        {
            min = 0;
            incHour();
        }
    }
    void incHour()
    {
        if (hour < 23)
            hour++;
        else
            hour = 0;
    }

  public:
    void tick() { incSec(); }
    void reset() { hour = min = sec = 0; }
    void print() { cout << hour << ':' << min << ':' << sec << "\r"; }
};

int main()
{

    Clock c;
    c.reset();
    while (1)
    {
        c.print();
        c.tick();
    }
}