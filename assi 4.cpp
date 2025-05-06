#include <iostream>
#include <string>
using namespace std;

// Base Class: Employee
class Employee {
protected:
    string name;
    int id;
    float salary;
public:
    Employee(string n, int i, float s) : name(n), id(i), salary(s) {}
    virtual void print_info() = 0;  // Pure virtual function to print info
    virtual string get_info() = 0;  // Pure virtual function to get info
};

// Derived Class: Student (inherits from Employee)
class Student : public Employee {
protected:
    string major;
public:
    Student(string n, int i) : Employee(n, i, 0.0) {}  // Students don't have salary
    void print_info() override {
        cout << "Student Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Major: " << major << endl;
    }
    string get_info() override {
        return name + " (Student)";
    }
};

// Derived Class: Graduate (inherits from Student)
class Graduate : public Student {
protected:
    string thesis_topic;
public:
    Graduate(string n, int i, string thesis) : Student(n, i), thesis_topic(thesis) {}
    void print_info() override {
        cout << "Graduate Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Thesis Topic: " << thesis_topic << endl;
    }
    string get_info() override {
        return name + " (Graduate)";
    }
};

// Derived Class: Alumnus (inherits from Graduate)
class Alumnus : public Graduate {
protected:
    string year_of_graduation;
public:
    Alumnus(string n, int i, string thesis, string year) : Graduate(n, i, thesis), year_of_graduation(year) {}
    void print_info() override {
        cout << "Alumnus Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Thesis Topic: " << thesis_topic << ", Year of Graduation: " << year_of_graduation << endl;
    }
    string get_info() override {
        return name + " (Alumnus)";
    }
};

// Derived Class: Instructor
class Instructor : public Employee {
protected:
    string department;
public:
    Instructor(string n, int i, float s, string dept) : Employee(n, i, s), department(dept) {}
    void print_info() override {
        cout << "Instructor Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << ", Department: " << department << endl;
    }
    string get_info() override {
        return name + " (" + department + ")";
    }
};

// Derived Class: Professor (inherits from Instructor)
class Professor : public Instructor {
protected:
    string title;
public:
    Professor(string n, int i, float s, string dept, string t) : Instructor(n, i, s, dept), title(t) {}
    void print_info() override {
        cout << "Professor Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << ", Department: " << department << ", Title: " << title << endl;
    }
    string get_info() override {
        return name + " (Professor)";
    }
};

// Derived Class: Staff
class Staff : public Employee {
protected:
    string role;
public:
    Staff(string n, int i, float s, string r) : Employee(n, i, s), role(r) {}
    void print_info() override {
        cout << "Staff Info: " << endl;
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << ", Role: " << role << endl;
    }
    string get_info() override {
        return name + " (" + role + ")";
    }
};

// Main function to test the code
int main() {
    // Create objects of each class
    Professor prof("Dr. Smith", 101, 90000, "Computer Science", "Full Professor");
    prof.print_info();
    
    Staff staff("John Doe", 201, 45000, "Lab Technician");
    staff.print_info();
    
    Alumnus alumnus("Alice Williams", 301, "AI in Healthcare", "2020");
    alumnus.print_info();
    
    Graduate grad("Bob Johnson", 401, "Data Science in Education");
    grad.print_info();
    
    return 0;
}

