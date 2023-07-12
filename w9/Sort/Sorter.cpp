#include "Sorter.h"

void SelectionSorter::sort(float* a, int n) {
    int i, j, max;
    float temp;

    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++)
            if (a[max] > a[j])
                max = j;
        temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }
}

const char* SelectionSorter::name() const {
    return "Selection Sorter";
}

void BubbleSorter::sort(float* a, int n) {
    int i, j;
    float temp;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

const char* BubbleSorter::name() const {
    return "Bubble Sorter";
}

iSorter* CreateSorter(int i) {
    iSorter* sorter = nullptr;
    switch (i) {
    case 0:
        sorter = new SelectionSorter();
        break;
    case 1:
        sorter = new BubbleSorter();
        break;
    }
    return sorter;
}

int noOfSorters() {
    return 2;
}