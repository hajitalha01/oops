#include <iostream>
using namespace std;

class Student {
private:
    int ID;
    float* grades;
    int numGrades;

public:
    Student(int id, int num) {
        ID = id;
        numGrades = num;
        grades = new float[numGrades];
    }

    Student(const Student& obj) {
        ID = obj.ID;
        numGrades = obj.numGrades;
        grades = new float[numGrades];
        for (int i = 0; i < numGrades; i++) {
            grades[i] = obj.grades[i];
        }
    }

    void setGrades(float g[]) {
        for (int i = 0; i < numGrades; i++) {
            grades[i] = g[i];
        }
    }

    void modifyGrade(int index, float newGrade) {
        if (index >= 0 && index < numGrades) {
            grades[index] = newGrade;
        } else {
            cout << "Invalid index!\n";
        }
    }

    void display() {
        cout << "Student ID: " << ID << ", Grades: ";
        for (int i = 0; i < numGrades; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }

    ~Student() {
        delete[] grades;
    }
};

int main() {
    int numgrade = 3;
    float gradeArray[3] = {65.4, 34.0, 65.4};

    Student student1(102, numgrade);
    student1.setGrades(gradeArray);

    Student student2 = student1;

    cout << "\nBefore modifying student1:\n";
    student1.display();
    student2.display();

    student1.modifyGrade(0, 99.0);

    cout << "\nAfter modifying student1 first grade:\n";
    student1.display();
    student2.display();

    return 0;
}
