#include <iostream>
#include <cmath> // For sqrt() function

using namespace std;

// Class: Point
class Point {
public:
    float x, y; // Coordinates of the point

    // Constructor to initialize point with x and y values
    Point(float x_coord, float y_coord) : x(x_coord), y(y_coord) {}
};

// Class: Line
class Line {
public:
    Point start, end; // Start and end points of the line

    // Constructor to initialize start and end points
    Line(Point s, Point e) : start(s), end(e) {}

    // Function to calculate and return the length of the line
    float length() {
        return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    }
};

// Class: Triangle
class Triangle {
public:
    Line base, height, hypotenuse; // Three lines of the triangle

    // Constructor to initialize the three sides of the triangle
    Triangle(Line b, Line h, Line hypo) : base(b), height(h), hypotenuse(hypo) {}

    // Function to calculate and return the area of the triangle using base and height
    float area() {
        return 0.5 * base.length() * height.length(); // Area formula: 0.5 * base * height
    }
};

int main() {
    // Create points
    Point p1(0, 0); // Point (0, 0)
    Point p2(4, 0); // Point (4, 0)
    Point p3(0, 3); // Point (0, 3)

    // Create lines (base, height, hypotenuse)
    Line base(p1, p2);        // Base: Line from (0, 0) to (4, 0)
    Line height(p1, p3);      // Height: Line from (0, 0) to (0, 3)
    Line hypotenuse(p2, p3);  // Hypotenuse: Line from (4, 0) to (0, 3)

    // Create triangle
    Triangle triangle(base, height, hypotenuse);

    // Print area of the triangle
    cout << "Area of the triangle: " << triangle.area() << endl;

    // Print length of each side of the triangle
    cout << "Base Length: " << base.length() << endl;
    cout << "Height Length: " << height.length() << endl;
    cout << "Hypotenuse Length: " << hypotenuse.length() << endl;

    return 0;
}

