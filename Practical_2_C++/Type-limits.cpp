#include <iostream>
#include <limits>
#include <iomanip> // Required for std::scientific

/**
 * @brief Prints properties for common integral types.
 */
void print_integral_properties() {
    std::cout << "--- Properties for int ---\n";
    std::cout << "Number of bits used: " << sizeof(int) * 8 << '\n';
    std::cout << "Range of values: [" << std::numeric_limits<int>::min() << ", " << std::numeric_limits<int>::max() << "]\n";
    std::cout << "Signedness: " << (std::numeric_limits<int>::is_signed ? "Signed" : "Unsigned") << "\n\n";

    std::cout << "--- Properties for unsigned long long ---\n";
    std::cout << "Number of bits used: " << sizeof(unsigned long long) * 8 << '\n';
    std::cout << "Range of values: [" << std::numeric_limits<unsigned long long>::min() << ", " << std::numeric_limits<unsigned long long>::max() << "]\n";
    std::cout << "Signedness: " << (std::numeric_limits<unsigned long long>::is_signed ? "Signed" : "Unsigned") << "\n\n";
}

/**
 * @brief Prints properties for common floating-point types.
 */
void print_floating_point_properties() {
    std::cout << "--- Properties for double ---\n";
    std::cout << "Number of bits for mantissa (base 2): " << std::numeric_limits<double>::digits << '\n';
    std::cout << "Range of values: [" << std::numeric_limits<double>::lowest() << ", " << std::numeric_limits<double>::max() << "]\n";
    std::cout << "Range of exponent (base 2): [" << std::numeric_limits<double>::min_exponent << ", " << std::numeric_limits<double>::max_exponent << "]\n";
    std::cout << "Smallest value x such that 1 + x > 1 (epsilon): " << std::numeric_limits<double>::epsilon() << "\n\n";

    std::cout << "--- Properties for float ---\n";
    std::cout << "Number of bits for mantissa (base 2): " << std::numeric_limits<float>::digits << '\n';
    std::cout << "Range of values: [" << std::numeric_limits<float>::lowest() << ", " << std::numeric_limits<float>::max() << "]\n";
    std::cout << "Range of exponent (base 2): [" << std::numeric_limits<float>::min_exponent << ", " << std::numeric_limits<float>::max_exponent << "]\n";
    std::cout << "Smallest value x such that 1 + x > 1 (epsilon): " << std::numeric_limits<float>::epsilon() << "\n\n";
}

int main() {
    // Set output to scientific notation for floating point numbers for better readability
    std::cout << std::scientific;

    std::cout << "====== Investigating Built-in Type Limits ======\n\n";
    
    print_integral_properties();
    print_floating_point_properties();

    return 0;
}
