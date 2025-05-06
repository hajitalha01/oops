#include <iostream>
using namespace std;

const int MAX_EXP = 100; // Maximum exponent allowed

class Polynomial {
private:
    int coeff[MAX_EXP + 1]; // Index = exponent, value = coefficient

public:
    // Default Constructor
    Polynomial() {
        for (int i = 0; i <= MAX_EXP; i++)
            coeff[i] = 0;
    }

    // Copy Constructor
    Polynomial(const Polynomial& p) {
        for (int i = 0; i <= MAX_EXP; i++)
            coeff[i] = p.coeff[i];
    }

    // Destructor
    ~Polynomial() {
        // No dynamic memory used, nothing needed here
    }

    // Set a term (coefficient at a specific exponent)
    void setTerm(int coefficient, int exponent) {
        if (exponent >= 0 && exponent <= MAX_EXP)
            coeff[exponent] = coefficient;
    }

    // Get a term (coefficient of specific exponent)
    int getTerm(int exponent) const {
        if (exponent >= 0 && exponent <= MAX_EXP)
            return coeff[exponent];
        return 0;
    }

    // Display polynomial
    void show() const {
        bool first = true;
        for (int i = MAX_EXP; i >= 0; i--) {
            if (coeff[i] != 0) {
                if (!first && coeff[i] > 0) cout << " + ";
                if (coeff[i] < 0) cout << " - ";
                cout << (coeff[i] < 0 ? -coeff[i] : coeff[i]);
                if (i > 0) cout << "x^" << i;
                first = false;
            }
        }
        if (first) cout << "0";
        cout << endl;
    }

    // Operator Overloads

    // +
    Polynomial operator+(const Polynomial& rhs) const {
        Polynomial result;
        for (int i = 0; i <= MAX_EXP; i++)
            result.coeff[i] = coeff[i] + rhs.coeff[i];
        return result;
    }

    // -
    Polynomial operator-(const Polynomial& rhs) const {
        Polynomial result;
        for (int i = 0; i <= MAX_EXP; i++)
            result.coeff[i] = coeff[i] - rhs.coeff[i];
        return result;
    }

    // ==
    bool operator==(const Polynomial& rhs) const {
        for (int i = 0; i <= MAX_EXP; i++) {
            if (coeff[i] != rhs.coeff[i])
                return false;
        }
        return true;
    }

    // *
    Polynomial operator*(const Polynomial& rhs) const {
        Polynomial result;
        for (int i = 0; i <= MAX_EXP; i++) {
            for (int j = 0; j <= MAX_EXP; j++) {
                if (i + j <= MAX_EXP)
                    result.coeff[i + j] += coeff[i] * rhs.coeff[j];
            }
        }
        return result;
    }

    // +=
    Polynomial& operator+=(const Polynomial& rhs) {
        for (int i = 0; i <= MAX_EXP; i++)
            coeff[i] += rhs.coeff[i];
        return *this;
    }

    // -=
    Polynomial& operator-=(const Polynomial& rhs) {
        for (int i = 0; i <= MAX_EXP; i++)
            coeff[i] -= rhs.coeff[i];
        return *this;
    }

    // *=
    Polynomial& operator*=(const Polynomial& rhs) {
        Polynomial result;
        for (int i = 0; i <= MAX_EXP; i++) {
            for (int j = 0; j <= MAX_EXP; j++) {
                if (i + j <= MAX_EXP)
                    result.coeff[i + j] += coeff[i] * rhs.coeff[j];
            }
        }
        *this = result;
        return *this;
    }
};

// Main function for testing
int main() {
    Polynomial p1, p2, p3;

    // Set p1 = 2x^2 + 3x + 5
    p1.setTerm(2, 2);
    p1.setTerm(3, 1);
    p1.setTerm(5, 0);

    // Set p2 = x^3 + 4x^2 + 1
    p2.setTerm(1, 3);
    p2.setTerm(4, 2);
    p2.setTerm(1, 0);

    cout << "Polynomial p1: ";
    p1.show();

    cout << "Polynomial p2: ";
    p2.show();

    // Addition
    p3 = p1 + p2;
    cout << "\np1 + p2 = ";
    p3.show();

    // Subtraction
    p3 = p1 - p2;
    cout << "p1 - p2 = ";
    p3.show();

    // Multiplication
    p3 = p1 * p2;
    cout << "p1 * p2 = ";
    p3.show();

    // Equality
    cout << "\nAre p1 and p2 equal? ";
    cout << (p1 == p2 ? "Yes" : "No") << endl;

    // +=
    p1 += p2;
    cout << "\np1 += p2: ";
    p1.show();

    // -=
    p1 -= p2;
    cout << "p1 -= p2: ";
    p1.show();

    // *=
    p1 *= p2;
    cout << "p1 *= p2: ";
    p1.show();

    return 0;
}

