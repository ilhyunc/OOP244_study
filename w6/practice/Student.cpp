#include "Student.h"
using namespace std;

Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int n) {
    *this = Student(n, nullptr, 0);
}

Student::Student(int sn, const float* g, int ng_) {
    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
    if (valid)
        for (int i = 0; i < ng_ && valid; i++)
            valid = g[i] >= 0.0f && g[i] <= 100.0f;

    if (valid) {
        // accept the client's data
        no = sn;
        ng = ng_ < NG ? ng_ : NG;
        for (int i = 0; i < ng; i++)
            grade[i] = g[i];
    }
    else {
        *this = Student();
    }
}

void Student::read(istream& is) {
    int no;          // will hold the student number
    int ng;          // will hold the number of grades
    float grade[NG]; // will hold the grades

    cout << "Student Number : ";
    is >> no;
    cout << "Number of Grades : ";
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        cout << "Grade " << i + 1 << " : ";
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(no, grade, ng);
    // if data is valid, the temporary object into the current object 
    if (temp.no != 0)
        *this = temp;
}

void Student::display(ostream& os) const {
    if (no > 0) {
        os << no << ":\n";
        os.setf(ios::fixed);
        os.precision(2);
        for (int i = 0; i < ng; i++) {
            os.width(6);
            os << grade[i] << endl;
        }
        os.unsetf(ios::fixed);
        os.precision(6);
    }
    else {
        os << "no data available" << endl;
    }
}

std::ostream& operator<<(ostream& os, const Student& s) {
    s.display(os);
    return os;
}

std::istream& operator>>(istream& is, Student& s) {
    s.read(is);
    return is;
}