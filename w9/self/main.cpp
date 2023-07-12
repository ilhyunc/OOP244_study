#include <iostream>
#include "iPerson.h"

const int NP = 5;

int main() {
    iPerson* p[NP];
    for (int i = 0; i < NP; i++)
        p[i] = nullptr;

    int n = 0;
    bool quit = false;
    do {
        iPerson* ptemp = CreatePerson();
        if (ptemp != nullptr) {
            p[n++] = ptemp;
        }
        else {
            quit = true;
        }
    } while (n < NP && !quit);

    for (int j = 0; j < n; j++) {
        p[j]->display(std::cout);
        std::cout << std::endl;
    }

    for (int j = 0; j < n; j++)
        delete p[j];
}