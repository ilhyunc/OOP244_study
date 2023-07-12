#include <iostream> // for std::ostream, std::istream
const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void read(std::istream&);
    void display(std::ostream& os) const;
};

std::istream& operator>>(std::istream& is, Student& s);
std::ostream& operator<<(std::ostream& os, const Student& s);
