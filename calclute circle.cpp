#include <iostream>
using namespace std;

class Circle {
public:
    double x, y, radius;

    // Default constructor
    Circle() {
        x = 0;
        y = 0;
        radius = 0;
    }

    // Parameterized constructor
    Circle(double xVal, double yVal, double r) {
        x = xVal;
        y = yVal;
        radius = r;
    }

    // Set values function
    void setValues(double xVal, double yVal, double r) {
        x = xVal;
        y = yVal;
        radius = r;
    }

    // Calculate area
    double area() {
        return 3.14 * radius * radius;
    }

    // Calculate circumference
    double circumference() {
        return 2 * 3.14 * radius;
    }

    // Print circle details
    void print() {
        cout << "Center: (" << x << ", " << y << ")\n";
        cout << "Radius: " << radius << "\n";
    }
};

int main() {
    Circle c1;
    c1.print();

    Circle c2(5, 6, 10);
    c2.print();
    
    c1.setValues(2, 3, 7);
    c1.print();

    cout << "Area: " << c1.area() << "\n";
    cout << "Circumference: " << c1.circumference() << "\n";

    return 0;
}

