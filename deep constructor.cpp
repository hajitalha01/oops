#include<iostream>
using namespace std;

class polygon {
private:
    float length;
    float* width;

public:
    // Parameterized constructor
    polygon(float l, float w) {
        length = l;
        width = new float(w);  // Dynamically allocated memory for width
    }

    // Deep Copy Constructor
    polygon(const polygon& obj) {
        length = obj.length;
        width = new float(*(obj.width));  // Nayi memory allocate ki aur value copy ki
    }

    // Display function to print length and width
    void disply() {
        cout << "length : " << length << "   width : " << *width << endl;
    }

    // Modify width
    void modifywidth(float w) {
        *width = w;
    }

    // Destructor
    ~polygon() {
        delete width;  // Free the dynamically allocated memory
        cout << endl << "Destructor called, freeing memory." << endl;
    }
};

int main() {
    cout << "Copy Deep Constructor :" << endl;
    polygon one(35.2, 23.1);  // Object one created
    polygon two = one;         // Deep copy constructor called

    cout << "Original Objects:" << endl;
    one.disply();               // Display one
    two.disply();               // Display two

    one.modifywidth(30.2);      // Modify one’s width
    cout << endl << "After modifying 'one':" << endl;
    one.disply();               // Display one after modification
    two.disply();               // Display two (should remain the same)

    return 0;
}

