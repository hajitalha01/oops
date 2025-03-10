#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Parameterized Constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized Constructor Called" << endl;
    }

    // Copy Constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        cout << "Copy Constructor Called" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("John", 30); // Calls Parameterized Constructor
    Person p2 = p1; // Calls Copy Constructor
    p2.display();
    return 0;
}

