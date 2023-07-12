#include "iSorter.h"

class SelectionSorter : public iSorter {
public:
    void sort(float*, int);
    const char* name() const;
};

class BubbleSorter : public iSorter {
public:
    void sort(float*, int);
    const char* name() const;
};

iSorter* CreateSorter(int);
int noOfSorters();