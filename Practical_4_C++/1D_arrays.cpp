#include <iostream>

// Function to compute partial sums
// Takes input array 'a' and output array 'b', both of length 20
void partial_sums(int a[], int b[]) {
    b[0] = a[0];  // First partial sum is just a[0]
    
    // For each position k, compute sum of a[0] through a[k]
    for (int k = 1; k < 20; k++) {
        b[k] = b[k-1] + a[k];  // Add current element to previous partial sum
    }
}

int main() {
    int a[20];  // Input array
    int b[20];  // Output array for partial sums
    
    // Initialize array a with values a[i] = i
    std::cout << "Input array (a[i] = i):" << std::endl;
    for (int i = 0; i < 20; i++) {
        a[i] = i;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Compute partial sums
    partial_sums(a, b);
    
    // Print the first 20 triangular numbers
    std::cout << "First 20 triangular numbers (partial sums):" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }
    
    return 0;
}