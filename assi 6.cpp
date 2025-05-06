#include <iostream>
#include <cstring>  // Add this header for 'strncpy' function
#include <string>
using namespace std;

class Date {
public:
    int YY, MM, DD;

    Date() : YY(0), MM(0), DD(0) {}  // No-argument constructor

    Date(int y, int m, int d) : YY(y), MM(m), DD(d) {}  // 3-argument constructor
};

class Time {
public:
    int HH, MM;

    Time() : HH(0), MM(0) {}  // No-argument constructor

    Time(int h, int m) : HH(h), MM(m) {}  // 3-argument constructor
};

class Location {
public:
    double Latitude, Longitude;

    Location() : Latitude(0.0), Longitude(0.0) {}  // No-argument constructor

    Location(double lat, double lon) : Latitude(lat), Longitude(lon) {}  // 2-argument constructor
};

class Prayer {
public:
    char Prayer_Name[20];
    Date Today;
    Time Start_Time;

    Prayer() {
        Prayer_Name[0] = '\0';
    }  // No-argument constructor

    Prayer(const char* name, Date date, Time time) {
        strncpy(Prayer_Name, name, sizeof(Prayer_Name) - 1);
        Prayer_Name[sizeof(Prayer_Name) - 1] = '\0';  // Ensures the name is properly null-terminated
        Today = date;
        Start_Time = time;
    }  // 3-argument constructor
};

class Prayer_Times {
public:
    Location Loc;
    Prayer Prayers[7];  // Array to store 7 prayers

    void Get_Location() {
        cout << "Please Enter Your Location\n";
        cout << "Enter Latitude: ";
        cin >> Loc.Latitude;
        cout << "Enter Longitude: ";
        cin >> Loc.Longitude;
    }

    void Show_Location() {
        cout << "Location: " << Loc.Latitude << ", " << Loc.Longitude << endl;
    }

    void Get_Times() {
        int year, month, day, hh, mm;

        cout << "Enter year month (January = 1) and date: ";
        cin >> year >> month >> day;
        Date date(year, month, day);

        // For each prayer, we take time input
        for (int i = 0; i < 7; i++) {
            cout << "Enter Time of " << getPrayerName(i) << " (hh mm): ";
            cin >> hh >> mm;
            Time time(hh, mm);
            Prayers[i] = Prayer(getPrayerName(i), date, time);
        }
    }

    void Show_Times() {
        cout << "-------------------------------------------------\n";
        cout << "Date: " << getMonthName(Prayers[0].Today.MM) << " " << Prayers[0].Today.DD << ", " << Prayers[0].Today.YY << endl;
        Show_Location();

        // Show times for all prayers
        for (int i = 0; i < 7; i++) {
            cout << getPrayerName(i) << ": " << formatTime(Prayers[i].Start_Time) << endl;
        }
    }

private:
    const char* getPrayerName(int i) {
        const char* prayers[] = {"Fajr", "Sunrise", "Dhuhr", "Asr", "Sunset", "Maghrib", "Isha"};
        return prayers[i];
    }

    const char* getMonthName(int month) {
        const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return months[month - 1];
    }

    string formatTime(Time time) {
        string timeStr = (time.HH < 10 ? "0" : "") + to_string(time.HH) + ":" + (time.MM < 10 ? "0" : "") + to_string(time.MM);
        return timeStr + (time.HH < 12 ? " am" : " pm");
    }
};

int main() {
    Prayer_Times pt;
    pt.Get_Location();
    pt.Get_Times();
    pt.Show_Times();
    return 0;
}

