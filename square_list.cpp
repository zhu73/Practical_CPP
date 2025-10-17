#include <iostream>

int main()
{
    int n;
    std::cout << "Please enter the maximum square: ";
    std::cin >> n;

    while (n < 0)
    {
        std::cout << "Invalid input. Please enter a non-negative number: ";
        std::cin >> n;
    }

    for (int i = 0; i <= n; i++)
    {
        // Change this line to output in "x y" format
        std::cout << i << " " << i * i << std::endl;
    }
    
    return 0;
}