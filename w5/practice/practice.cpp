#include <iostream>

using namespace std;
const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    const Student& operator+=(float);
    void display() const;
    friend bool operator==(const Student&, const Student&);
};

Student operator+(const Student&, float);
Student operator+(float, const Student&);

Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int n) {
    float g[] = { 0.0f };
    *this = Student(n, g, 0);
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

void Student::display() const {
    if (no > 0) {
        cout << no << ":\n";
        cout.setf(ios::fixed);
        cout.precision(2);
        for (int i = 0; i < ng; i++) {
            cout.width(6);
            cout << grade[i] << endl;
        }
        cout.unsetf(ios::fixed);
        cout.precision(6);
    }
    else {
        cout << "no data available" << endl;
    }
}

const Student& Student::operator+=(float g) {
    if (no != 0 && ng < NG && g >= 0.f && g <= 100.f)
        grade[ng++] = g;
    return *this;
}

Student operator+(const Student& student, float grade) {
    Student copy = student; // makes a copy
    copy += grade;          // calls the += operator on copy 
    return copy;            // return updated copy
}

Student operator+(float grade, const Student& student) {
    return student + grade; // calls operator+(const
    //    Student&, float)
}

bool operator==(const Student& lhs, const Student& rhs) {
    bool same = lhs.no == rhs.no && lhs.ng == rhs.ng;
    for (int i = 0; i < lhs.ng && same; i++)
        same = lhs.grade[i] == rhs.grade[i];
    return same;
}

int main() {
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3), harry_(1234, gh, 3);
    harry_ += 63.7f;
    if (harry == harry_)
        cout << "are identical" << endl;
    else
        cout << "are different" << endl;
}