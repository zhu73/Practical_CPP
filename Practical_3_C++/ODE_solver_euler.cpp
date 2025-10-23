#include <iostream>
#include <fstream>
#include <cmath>

// This is the function f(y,t) from the ODE dy/dt = f(y,t).
// In this case, f(y,t) = sqrt(y), so it only depends on y.
double f(double y) {
    return sqrt(y);
}

int main() {
    // Declare variables for user input
    double T_max, y0, dt;

    // Get input from the user, providing suggested values
    std::cout << "Enter the maximum time T (e.g., 10): ";
    std::cin >> T_max;

    std::cout << "Enter the initial value y0 (e.g., 1): ";
    std::cin >> y0;

    std::cout << "Enter the time-step dt (e.g., 0.001): ";
    std::cin >> dt;

    // Open the output file
    std::ofstream outfile("ode.dat");
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file ode.dat for writing." << std::endl;
        return 1; // Exit with an error code
    }

    // Initialize time and y for the simulation
    double t = 0.0;
    double y = y0;

    // The main loop for the Euler method.
    // A while loop is used to avoid floating-point precision issues
    // that can occur with for loops and non-integer steps.
    while (t <= T_max) {
        // Write the current time and y value to the file, separated by a space
        outfile << t << " " << y << std::endl;

        // Update y using the Euler formula: y_new = y_old + dt * f(y_old)
        y += dt * f(y);

        // Increment the time
        t += dt;
    }

    // Close the file
    outfile.close();

    std::cout << "Successfully wrote data to ode.dat" << std::endl;

    return 0;
}