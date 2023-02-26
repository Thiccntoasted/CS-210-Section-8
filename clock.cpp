#include "clock.h"

class Clock {

public:
    Clock();
    Clock(int hrs, int mins, int secs);
    void setHours(int hrs);
    void setMinutes(int mins);
    void setSeconds(int secs);
    int getHrs();
    int getMinutes();
    int getSeconds();
    void display24format();
    void display12format();
    void incrementHr();
    void incrementMinute();
    void incrementSec();

private:
    int hours;
    int minutes;
    int seconds;
};

// Default constructor
Clock::Clock() {
    hours = minutes = seconds = 0;
}

// Parameterized constructor
Clock::Clock(int hrs, int mins, int secs) {
    setHours(hrs);
    setMinutes(mins);
    setSeconds(secs);
}

// Setters
void Clock::setHours(int hrs) {
    if (hrs > 23) {
        hours = 0;
    } else {
        hours = hrs;
    }
}

void Clock::setMinutes(int mins) {
    if (mins > 59) {
        minutes = mins % 60;
        hours += mins / 60;
    } else {
        minutes = mins;
    }
    if (hours > 23) {
        hours = hours % 24;
    }
}

void Clock::setSeconds(int secs) {
    if (secs > 59) {
        seconds = secs % 60;
        incrementMinute();
    } else {
        seconds = secs;
    }
}

// Getters
int Clock::getHrs() {
    return hours;
}

int Clock::getMinutes() {
    return minutes;
}

int Clock::getSeconds() {
    return seconds;
}

// Display 24 format
void Clock::display24format() {
    if (hours < 10) cout << "0";
    cout << hours << ":";
    if (minutes < 10) cout << "0";
    cout << minutes << ":";
    if (seconds < 10) cout << "0";
    cout << seconds;
}

// Display 12 format
void Clock::display12format() {
    int displayHrs = hours % 12;
    if (displayHrs == 0) displayHrs = 12;
    if (displayHrs < 10) cout << "0";
    cout << displayHrs << ":";
    if (minutes < 10) cout << "0";
    cout << minutes << ":";
    if (seconds < 10) cout << "0";
    cout << seconds;
    if (hours < 12) cout << " AM";
    else cout << " PM";
}

void Clock::incrementHr() {
    setHours(hours + 1);
}

void Clock::incrementMinute() {
    setMinutes(minutes + 1);
}

void Clock::incrementSec() {
    setSeconds(seconds + 1);
}
