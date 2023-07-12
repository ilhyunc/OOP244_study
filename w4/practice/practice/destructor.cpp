#include<cstring>
#include<iostream>
using namespace std;

class Foo {
    char F;
public:
    Foo(char ch = 'Y') {
        cout << (F = ch);
    }
    ~Foo() {
        cout << F;
    }
};

int main() {
    Foo F[2] = { 'Z' }; // Z Y
    Foo* p = new Foo('X'); // X
    return 0;
} // Y Z
