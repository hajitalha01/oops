#include <iostream>
using namespace std;

// Rational class for performing arithmetic on fractions
class Rational {
private:
    int numerator;
    int denominator;

    // Function to find GCD (Greatest Common Divisor) to reduce fraction
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    // Function to reduce the fraction
    void reduce() {
        int factor = gcd(numerator, denominator);
        numerator /= factor;
        denominator /= factor;
        if (denominator < 0) { // Keep denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor with default values
    Rational(int num = 0, int den = 1) {
        if (den == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            den = 1;
        }
        numerator = num;
        denominator = den;
        reduce();
    }

    // Addition of two Rational numbers
    Rational add(Rational other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Subtraction of two Rational numbers
    Rational subtract(Rational other) {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Multiplication of two Rational numbers
    Rational multiply(Rational other) {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Division of two Rational numbers
    Rational divide(Rational other) {
        if (other.numerator == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return *this;
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // Print Rational number in a/b form
    void printFraction() {
        cout << numerator << "/" << denominator << endl;
    }

    // Print Rational number in floating-point format
    void printFloat() {
        cout << static_cast<double>(numerator) / denominator << endl;
    }
};

int main() {
    Rational r1(2, 4), r2(3, 9);

    cout << "First Rational Number: ";
    r1.printFraction();
    cout << "Second Rational Number: ";
    r2.printFraction();

    Rational sum = r1.add(r2);
    cout << "Sum: ";
    sum.printFraction();

    Rational diff = r1.subtract(r2);
    cout << "Difference: ";
    diff.printFraction();

    Rational product = r1.multiply(r2);
    cout << "Product: ";
    product.printFraction();

    Rational quotient = r1.divide(r2);
    cout << "Quotient: ";
    quotient.printFraction();

    cout << "Floating Point Representation of Sum: ";
    sum.printFloat();

    return 0;
}

