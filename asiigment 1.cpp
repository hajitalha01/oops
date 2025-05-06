#include <iostream>
#include <cmath> // For fmod()
using namespace std;

class Distance {
private:
    int feet;
    double inches;

    void normalize() {
        if (inches >= 12) {
            feet += static_cast<int>(inches) / 12;
            inches = fmod(inches, 12);
        } else if (inches < 0) {
            int borrow = (static_cast<int>(-inches) / 12) + 1;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

public:
    // No-arg constructor
    Distance() {
        feet = 0;
        inches = 0.0;
    }

    // Two-arg constructor
    Distance(int f, double i) {
        feet = f;
        inches = i;
        normalize();
    }

    // get_data()
    void get_data() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }

    // show_data()
    void show_data() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Prefix ++
    Distance& operator++() {
        inches += 1;
        normalize();
        return *this;
    }

    // Postfix ++
    Distance operator++(int) {
        Distance temp = *this;
        inches += 1;
        normalize();
        return temp;
    }

    // Prefix --
    Distance& operator--() {
        inches -= 1;
        normalize();
        return *this;
    }

    // Postfix --
    Distance operator--(int) {
        Distance temp = *this;
        inches -= 1;
        normalize();
        return temp;
    }

    // + operator
    Distance operator+(const Distance& d) const {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;
        temp.normalize();
        return temp;
    }

    // - operator
    Distance operator-(const Distance& d) const {
        Distance temp;
        temp.feet = feet - d.feet;
        temp.inches = inches - d.inches;
        temp.normalize();
        return temp;
    }

    // * operator
    Distance operator*(const Distance& d) const {
        double total1 = feet * 12 + inches;
        double total2 = d.feet * 12 + d.inches;
        double result = total1 * total2;
        Distance temp;
        temp.feet = static_cast<int>(result) / 12;
        temp.inches = fmod(result, 12);
        return temp;
    }

    // == operator
    bool operator==(const Distance& d) const {
        return (feet == d.feet && inches == d.inches);
    }

    // += operator
    Distance& operator+=(const Distance& d) {
        feet += d.feet;
        inches += d.inches;
        normalize();
        return *this;
    }

    // -= operator
    Distance& operator-=(const Distance& d) {
        feet -= d.feet;
        inches -= d.inches;
        normalize();
        return *this;
    }

    // *= operator
    Distance& operator*=(const Distance& d) {
        double total1 = feet * 12 + inches;
        double total2 = d.feet * 12 + d.inches;
        double result = total1 * total2;
        feet = static_cast<int>(result) / 12;
        inches = fmod(result, 12);
        return *this;
    }
};

// Main function
int main() {
    Distance d1(5, 9.5), d2(3, 4.5), d3;

    cout << "Initial values:" << endl;
    cout << "d1 = "; d1.show_data();
    cout << "d2 = "; d2.show_data();

    // + operator
    d3 = d1 + d2;
    cout << "\nd1 + d2 = "; d3.show_data();

    // - operator
    d3 = d1 - d2;
    cout << "d1 - d2 = "; d3.show_data();

    // * operator
    d3 = d1 * d2;
    cout << "d1 * d2 = "; d3.show_data();

    // Prefix ++
    ++d1;
    cout << "\n++d1 = "; d1.show_data();

    // Postfix ++
    d1++;
    cout << "d1++ = "; d1.show_data();

    // Prefix --
    --d2;
    cout << "\n--d2 = "; d2.show_data();

    // Postfix --
    d2--;
    cout << "d2-- = "; d2.show_data();

    // == operator
    cout << "\nIs d1 == d2? " << (d1 == d2 ? "Yes" : "No") << endl;

    // += operator
    d1 += d2;
    cout << "\nd1 += d2 => d1 = "; d1.show_data();

    // -= operator
    d1 -= d2;
    cout << "d1 -= d2 => d1 = "; d1.show_data();

    // *= operator
    d1 *= d2;
    cout << "d1 *= d2 => d1 = "; d1.show_data();

    return 0;
}

