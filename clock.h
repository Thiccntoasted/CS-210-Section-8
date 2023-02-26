#include <iostream>
#include <string>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock() : hours(0), minutes(0), seconds(0) {} 
    Clock(int hours, int minutes, int seconds);
    void setTime(int hours, int minutes, int seconds);
    string getTime();
    void incrementHour();
    void incrementMinute();
    void incrementSecond();
    void incrementTime(int hours, int minutes, int seconds);
};
