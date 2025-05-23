#include "iter.hpp"
#include <iostream>

template <typename T>
void increment(T& element) {
    element += 1;
}

template <typename T>
void printElement(const T& element) {
        std::cout << element << " ";
}

void putcharr(char &c){
    std::cout << "|" <<  c << "|" << std::endl;
}

int main() {

    int intArr[] = {1, 2, 3, 4, 5};
    int intLength = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << std::string(29, '=') << "\n";
    std::cout << "Original int array: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << "\n" << std::string(29, '=') << "\n";
    
    iter(intArr, intLength, increment<int>);
    std::cout << "After increment: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << "\n" << std::string(29, '=') << "\n";
    
    std::string strArr[] = {"Hello", "World", "!"};
    int strLength = sizeof(strArr) / sizeof(strArr[0]);
    
    std::cout << "String array: ";
    iter(strArr, strLength, printElement<std::string>);
    std::cout << "\n" << std::string(29, '=') << "\n";
    
    std::cout << "String Characters: \n";
    iter(&strArr[0][0], strArr[0].length(), putcharr);

    return 0;
}