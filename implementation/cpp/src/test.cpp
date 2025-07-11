#include <iostream>

#include "maths_pkg/basic/add.hpp"
#include "maths_pkg/basic/sub.hpp"
#include "maths_pkg/advanced/multiply.hpp"
#include "maths_pkg/advanced/divide.hpp"

int main() {
    
    int a = 6;
    int b = 3;

    std::cerr << "Adding " << a << " and " << b << ": " << add(a, b) << std::endl;
    std::cerr << "Subtracting " << a << " and " << b << ": " << subtract(a, b) << std::endl;
    std::cerr << "Multiplying " << a << " and " << b << ": " << multiply(a, b) << std::endl;
    std::cerr << "Dividing " << a << " and " << b << ": " << divide(a, b) << std::endl;
    return 0;
}
