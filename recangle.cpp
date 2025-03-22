#include <iostream>
using namespace std;

class Rectangle {
public:
    int length, width;

    // Default constructor
    Rectangle() {
        length = 1;
        width = 1;
    }

    // Parameterized constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Set values function
    void set(int l, int w) {
        length = l;
        width = w;
    }

    // Calculate area
    int area() {
        return length * width;
    }

    // Calculate perimeter
    int perimeter() {
        return 2 * (length + width);
    }

    // Draw rectangle
    void draw() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (i == 0 || i == width - 1 || j == 0 || j == length - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Rectangle r1;
    r1.draw();
    
    Rectangle r2(10, 5);
    r2.draw();
    
    r1.set(7, 4);
    r1.draw();
    
    cout << "Area: " << r1.area() << "\n";
    cout << "Perimeter: " << r1.perimeter() << "\n";

    return 0;
}

