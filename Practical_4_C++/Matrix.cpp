#include <iostream>

// Function to calculate determinant of a 3x3 matrix
double determinant(const double matrix[3][3]) {
    double det = 0.0;
    
    // Using the rule of Sarrus for 3x3 determinant
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    
    return det;
}

// Function to calculate trace of a 3x3 matrix
double trace(const double matrix[3][3]) {
    // Trace is the sum of diagonal elements
    return matrix[0][0] + matrix[1][1] + matrix[2][2];
}

// Function to print a 3x3 matrix
void print_matrix(const double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    double matrix[3][3];
    
    std::cout << "Enter a 3x3 matrix (9 values, row by row):" << std::endl;
    
    // Read matrix from user
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
    
    // Display the matrix
    std::cout << "\nYour matrix is:" << std::endl;
    print_matrix(matrix);
    
    // Calculate and display determinant
    double det = determinant(matrix);
    std::cout << "\nDeterminant: " << det << std::endl;
    
    // Calculate and display trace
    double tr = trace(matrix);
    std::cout << "Trace: " << tr << std::endl;
    
    return 0;
}
