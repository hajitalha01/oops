#include <iostream>
#include <cmath>
using namespace std;

// Base Class
class Shape {
public:
    string name;
    Shape(string n) { name = n; }
};

// 2D Base Class
class TwoDShape : public Shape {
public:
    TwoDShape(string n) : Shape(n) {}
    virtual void area() = 0; // Pure virtual function for area
};

// 3D Base Class
class ThreeDShape : public Shape {
public:
    ThreeDShape(string n) : Shape(n) {}
    virtual void volume() = 0; // Pure virtual function for volume
};

// 2D Shape: Circle
class Circle : public TwoDShape {
public:
    float radius;
    Circle(float r) : TwoDShape("Circle"), radius(r) {}
    void area() override {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

// 2D Shape: Square
class Square : public TwoDShape {
public:
    float side;
    Square(float s) : TwoDShape("Square"), side(s) {}
    void area() override {
        cout << "Area of Square: " << side * side << endl;
    }
};

// 2D Shape: Triangle
class Triangle : public TwoDShape {
public:
    float base, height;
    Triangle(float b, float h) : TwoDShape("Triangle"), base(b), height(h) {}
    void area() override {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }
};

// 2D Shape: Rectangle
class Rectangle : public TwoDShape {
public:
    float length, width;
    Rectangle(float l, float w) : TwoDShape("Rectangle"), length(l), width(w) {}
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

// 3D Shape: Sphere
class Sphere : public ThreeDShape {
public:
    float radius;
    Sphere(float r) : ThreeDShape("Sphere"), radius(r) {}
    void volume() override {
        cout << "Volume of Sphere: " << (4.0 / 3) * 3.14 * pow(radius, 3) << endl;
    }
};

// 3D Shape: Cylinder
class Cylinder : public ThreeDShape {
public:
    float radius, height;
    Cylinder(float r, float h) : ThreeDShape("Cylinder"), radius(r), height(h) {}
    void volume() override {
        cout << "Volume of Cylinder: " << 3.14 * radius * radius * height << endl;
    }
};

// Main function
int main() {
    // Create 2D Shape objects
    Circle c(5);
    Square s(4);
    Triangle t(3, 6);
    Rectangle r(4, 7);

    // Create 3D Shape objects
    Sphere sp(3);
    Cylinder cy(2, 5);

    // Display area for 2D shapes
    cout << "----- 2D Shapes -----" << endl;
    c.area();
    s.area();
    t.area();
    r.area();

    // Display volume for 3D shapes
    cout << "----- 3D Shapes -----" << endl;
    sp.volume();
    cy.volume();

    return 0;
}

