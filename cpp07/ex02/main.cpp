#include "Array.hpp"


int main() {
    // Create array of 5 integers
    Array<int> int_arr(5);
    
    // Initialize values
    for(size_t i = 0; i < int_arr.size(); ++i) {
        int_arr[i] = i * 10;
    }

    // Test copy constructor
    Array<int> int_arr2 = int_arr;
    int_arr2[0] = 100;

    // Test assignment operator
    Array<int> int_arr3(3);
    int_arr3 = int_arr;

    // Output results
    std::cout << "Original[0]: " << int_arr[0]   // 0
              << " Copy[0]: " << int_arr2[0]     // 100
              << " Assign[0]: " << int_arr3[0];  // 0

    return 0;
}