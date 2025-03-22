#include <iostream>
using namespace std;

class Time {
public:
    int hours, minutes, seconds;

    // Default constructor
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Parameterized constructor
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Set time function
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Print time in HH:MM:SS format
    void print() {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    // Tick function to increment time by one second
    void tick() {
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }

    // Add two Time objects
    Time add(Time t) {
        Time temp;
        temp.seconds = seconds + t.seconds;
        temp.minutes = minutes + t.minutes + temp.seconds / 60;
        temp.seconds %= 60;
        temp.hours = hours + t.hours + temp.minutes / 60;
        temp.minutes %= 60;
        temp.hours %= 24;
        return temp;
    }
};

int main() {
    Time t1(23, 59, 58);
    
    // Loop 1000 times, calling tick() and print()
    for (int i = 0; i < 1000; i++) {
        t1.tick();
        t1.print();
    }

    // Creating two time objects and adding them
    Time t2(12, 45, 30);
    Time t3(5, 20, 50);
    Time t4 = t2.add(t3);
    
    cout << "First Time: "; t2.print();
    cout << "Second Time: "; t3.print();
    cout << "Sum of Times: "; t4.print();
    
    return 0;
}

