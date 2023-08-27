#include <iostream>
using namespace std;

// Define a template class MathArray
template <typename T, int N>
class MathArray {
private:
    T elements[N]; // Array to store elements

public:
    // Constructor: Initialize elements with values 1, 2, ..., N
    MathArray() {
        for (int i = 0; i < N; ++i) {
            elements[i] = static_cast<T>(i + 1); // Initialize with values 1 to N
        }
    }

    // Calculate and return the sum of all elements
    T sum() const {
        T total = elements[0];
        for (int i = 1; i < N; ++i) {
            total += elements[i]; // Accumulate the sum
        }
        return total;
    }

    // Calculate and return the product of all elements
    T product() const {
        T result = elements[0];
        for (int i = 1; i < N; ++i) {
            result *= elements[i]; // Accumulate the product
        }
        return result;
    }
};

int main() {
    // Create MathArray instances with specific data types and sizes
    MathArray<int, 5> intArray;
    MathArray<double, 4> doubleArray;

    // Calculate and display the sum of intArray elements (1 + 2 + 3 + 4 + 5)
    cout << "Sum of intArray: " << intArray.sum() << endl;

    // Calculate and display the product of doubleArray elements (1 * 2 * 3 * 4)
    cout << "Product of doubleArray: " << doubleArray.product() << endl;

    return 0;
}

// Sum of intArray: 15
// Product of doubleArray: 24


