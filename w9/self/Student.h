#include <iostream>
#include "iPerson.h"
const int NC = 30;
const int NG = 20;

class Person : public iPerson {
    char name[NC + 1];
public:
    Person();
    Person(const char*);
    void display(std::ostream&) const;
};

class Student : public Person {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(const char*, int, const float*, int);
    void display(std::ostream&) const;
};

iPerson* CreatePerson();