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

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Alice", 25); // Passing values to the constructor
    p1.display();
    return 0;
}

