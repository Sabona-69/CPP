#include "Array.hpp"

int main() {
    // Test 1: Default constructor (empty array)
    Array<int> empty;
    try {
        std::cout << "Empty array size: " << empty.size() << std::endl;
        empty[0] = 42; // Should throw
    } catch (const std::exception& e) {
        std::cout << "Exceptiont Caught : " << e.what() << std::endl;
    }

    // Test 2: Constructor with size and value initialization
    Array<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << "Original array: \n" << arr << std::endl;
    
    // Test 3: Shallow copy via copy constructor
    Array<int> arrCopy(arr);
    arrCopy[0] = 100;
    arrCopy[1] = 200;
    arrCopy[2] = 300;
    std::cout << "After copy modification : \n" << arrCopy << std::endl;
    std::cout << "Original array: \n" << arr << std::endl;
    
    
    // Test 4: Assignment operator
    Array<int> arrAssign;
    arrAssign = arr;
    arrAssign[0] = 1000;
    arrAssign[1] = 2000;
    arrAssign[2] = 3000;
    std::cout << "After assignment modification : \n" << arrAssign << std::endl;
    std::cout << "Original array: \n" << arr << std::endl;

    // Test 5: Bounds checking
    try {
        std::cout << "Accessing invalid index: " << arr[3] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exceptiont Caught : " << e.what() << std::endl;
    }
    
    // Test 6: Test another type
    Array<std::string> str(3);
    str[0] = "abc";
    str[1] = "def";
    str[2] = "gih";
    std::cout << str << std::endl;
    
    // Test 7: Test default constructor with strings
    try
    {
        Array<std::string> str;
        str[0] = "abc";
        str[1] = "def";
        str[2] = "gih";
        std::cout << str;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exceptiont Caught : " << e.what() << std::endl;
    }
    
    // Test 8: Test const operator[]
    try
    {
        const Array<std::string> constStr(3);
        // constStr[0] = "abc";
        std::cout << "{" <<constStr[0] << "}" << std::endl;   
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Exceptiont Caught : " << e.what() << std::endl;
    }    
    
    return 0;
}