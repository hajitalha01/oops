#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Default Constructor
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Default Constructor Called" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1; // Default Constructor is called automatically
    p1.display();
    return 0;
}

