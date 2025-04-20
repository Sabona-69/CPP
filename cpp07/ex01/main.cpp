#include "iter.hpp"
#include <iostream>

class Awesome
{
    public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
    private:
    int _n;
    };

    std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

    template< typename T >
    void print( T const & x ) { std::cout << x << std::endl; return; }


    int main() {
    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];
    iter( tab, 5, print<const int>);
    iter( tab2, 5, print<Awesome>);
    return 0;
}

// template <typename T>
// void increment(T& element) {
//     element += 1;
// }

// template <typename T>
// void printElement(const T& element) {
//         std::cout << element << " ";
// }

// void putcharr(char &c){
//     std::cout << c << std::endl;
// }

// int main() {

//     int intArr[] = {1, 2, 3, 4, 5};
//     int intLength = sizeof(intArr) / sizeof(intArr[0]);

//     std::cout << "Original int array: ";
//     iter(intArr, intLength, printElement<int>);
//     std::cout << "\n" << std::string(29, '=') << "\n";
    
//     iter(intArr, intLength, increment<int>);
//     std::cout << "After increment: ";
//     iter(intArr, intLength, printElement<int>);
//     std::cout << "\n" << std::string(29, '=') << "\n";
    
//     std::string strArr[] = {"Hello", "World", "!"};
//     int strLength = sizeof(strArr) / sizeof(strArr[0]);
    
//     std::cout << "String array: ";
//     iter(strArr, strLength, printElement<std::string>);
//     std::cout << "\n" << std::string(29, '=') << "\n";

//     iter(&strArr[0][0], strArr[0].length(), putcharr);

//     return 0;
// }