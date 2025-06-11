#include <iostream>
#include "basic/add.hpp"
#include "basic/sub.hpp"
#include "advanced/multiply.hpp"
#include "advanced/divide.hpp"

int main() {
    
    int a = 6;
    int b = 3;

    std::cerr << "Adding " << a << " and " << b << ": " << add(a, b) << std::endl;
    std::cerr << "Subtracting " << a << " and " << b << ": " << subtract(a, b) << std::endl;
    std::cerr << "Multiplying " << a << " and " << b << ": " << multiply(a, b) << std::endl;
    std::cerr << "Dividing " << a << " and " << b << ": " << divide(a, b) << std::endl;
    return 0;
}
