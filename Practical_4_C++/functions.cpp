#include <cmath>
#include <iostream>

int sum(int a, int b){
    return a+b;
}

void decrease(int& a, int b){
    a -=b;
}

int q(double a, double b, double c, double& x1, double& x2) {
    double discriminant = b*b-4*a*c;

    if (discriminant < 0)
    {
        return 0;
    }
    if (discriminant == 0)
    {
        x1 = -b/(2*a);
        x2 = x1;
        return 1;
    }
    x1 = (-b + sqrt(discriminant)) / (2*a);
    x2 = (-b - sqrt(discriminant)) / (2*a);
    return 2;
}

int main() {
    // Test function 1: sum
    std::cout << "=== Testing sum ===" << std::endl;
    int result = sum(5, 3);
    std::cout << "sum(5, 3) = " << result << std::endl << std::endl;
    
    // Test function 2: decrease
    std::cout << "=== Testing decrease ===" << std::endl;
    int a = 10;
    std::cout << "Before: a = " << a << std::endl;
    decrease(a, 3);
    std::cout << "After decrease(a, 3): a = " << a << std::endl << std::endl;
    
    // Test function 3: q (quadratic solver)
    std::cout << "=== Testing quadratic solver ===" << std::endl;
    double x1, x2;
    
    // Case 1: Two solutions
    int num = q(1, -5, 6, x1, x2);
    std::cout << "x^2 - 5x + 6 = 0" << std::endl;
    std::cout << "Solutions: " << num << std::endl;
    std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl << std::endl;
    
    // Case 2: One solution
    num = q(1, -4, 4, x1, x2);
    std::cout << "x^2 - 4x + 4 = 0" << std::endl;
    std::cout << "Solutions: " << num << std::endl;
    std::cout << "x1 = " << x1 << std::endl << std::endl;
    
    // Case 3: No real solutions
    num = q(1, 1, 1, x1, x2);
    std::cout << "x^2 + x + 1 = 0" << std::endl;
    std::cout << "Solutions: " << num << " (complex)" << std::endl;
    
    return 0;
}
