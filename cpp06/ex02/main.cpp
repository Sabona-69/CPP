#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {

    Base	baseObj;
    Base*	basePtr;

    basePtr = baseObj.generate();
    baseObj.identify(basePtr);
    baseObj.identify(*basePtr);
}