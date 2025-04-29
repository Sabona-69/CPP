#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


class A{
    int i = 9;
    public:
        void push(){cout << i << endl;}; 
        void pop(){cout << i << endl;}; 
        void size(){cout << i << endl;}; 
};

class B : public A{

};


int main()
{
    // std::stack<int> arr;
    // // for (size_t i = 0; i < 10; i++)
    // // {
    // // }
    // for (size_t i = 0; i < arr.size(); i++)
    // {
        
    //     arr.push(i);
    //     arr.push(i + 1);
    //     arr.pop();
    //     std::cout << "i : " << i << "\tvalue :" << arr.top() <<"\n";
    // }
    // std::cout <<  

    B b;
    b.push();

}