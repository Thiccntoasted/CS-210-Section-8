#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "clock.h"

// Function prototypes
void display(Clock clock);
int menu();

int main()
{
    // Get current time
    time_t now = time(0);
    // Get seconds, minutes and hour
    struct tm timeSplitter;
    timeSplitter = *localtime(&now);
    // Create Clock object
    Clock clock(timeSplitter.tm_hour, timeSplitter.tm_min, timeSplitter.tm_sec);
    // Display formatted time
    display(clock);
    // Sleep for 1 second and clear screen
    Sleep(1000);
    system("CLS");

    // Display menu
    int opt = menu();
    // Loop until user selects "Exit Program"
    while (opt != 4) {
        switch (opt) {
            case 1:
                clock.incrementHr();
                break;
            case 2:
                clock.incrementMinute();
                break;
            case 3:
                clock.incrementSec();
                break;
        }
        // Display formatted time
        display(clock);
        // Sleep for 1 second and clear screen
        Sleep(1000);
        system("CLS");
        opt = menu();
    }
    return 0;
}

// Function to display time in 2 time formats
void display(Clock clock) {
    cout << "****************************** ******************************\n"
    << " * 12-Hour Clock * * 24-Hour Clock *\n"
    << " * ";
    clock.display12format();
    cout << " * * ";
    clock.display24format();
    cout << " *\n"
    << " ***************************** ******************************\n";
}

// Function to display menu and get user input
int menu() {
    int opt;
    cout << "\n******************************\n"
    << "* 1 - Add One Hour *\n"
    << "* 2 - Add One Minute *\n"
    << "* 3 - Add One Second *\n"
    << "* 4 - Exit Program *\n"
    << "******************************\n";
    cin >> opt;
    return opt;
}
