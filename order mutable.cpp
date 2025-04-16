#include <iostream>
#include <string>
using namespace std;

class HotelOrder {
private:
    const string customerName;  // Customer ka naam (change nahi ho sakta)
    mutable string orderedFood;  // Ordered food ka naam (change ho sakta hai)
    const int orderTimeLimit = 10;  // Order change karne ki time limit (10 minutes)
    mutable int timeElapsed;  // Time jo guzar gaya hai (change ho sakta hai)

public:
    // Constructor: Customer ka naam aur food set karta hai
    HotelOrder(string name, string food) : customerName(name), orderedFood(food), timeElapsed(0) {
        cout << name << " ordered: " << food << endl;
    }

    // Order change karne ka function
    void changeOrder(string newFood) const {
        if (timeElapsed < orderTimeLimit) {  // Agar time limit se pehle ho to order change kar sakte hain
            this->orderedFood = newFood;
            cout << "Order changed! New order: " << orderedFood << endl;
        } else {
            cout << "Time up! Order can't be changed now." << endl;
        }
    }

    // Time ko pass karne ka function
    void passTime(int minutes) const {
        timeElapsed += minutes;  // Time ko add karte hain
        cout << minutes << " minutes passed." << endl;
    }

    // Customer ka order dikhane ka function
    void showOrder() const {
        cout << "Customer: " << customerName << ", Ordered: " << orderedFood << endl;
    }

    // Destructor (automatically object destroy hone par call hota hai, memory free karne ke liye)
    ~HotelOrder() {}
};

int main() {
    // HotelOrder ka object banaya
    const HotelOrder order1("Talha", "Piza");

    // Show the initial order
    order1.showOrder();

    // Change order to "bred"
    order1.changeOrder("bred");

    // 9 minutes pass karte hain
    order1.passTime(9);

    // Change order to "berger"
    order1.changeOrder("berger");

    // 3 more minutes pass karte hain
    order1.passTime(3);

    // Try to change order again, but it will fail due to time limit
    order1.changeOrder("fruit");

    // Show the final order
    order1.showOrder();

    return 0;
}

