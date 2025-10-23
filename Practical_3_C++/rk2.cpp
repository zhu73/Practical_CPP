#include <iostream>
#include <fstream>
#include <cmath>

double f(double y) {
    return sqrt(y);
}

// Exact solution: y(t) = (sqrt(y0) + t/2)^2
double exact_solution(double t, double y0) {
    return pow(sqrt(y0) + t/2.0, 2);
}

int main(){
    double T_max, y0, dt;

    std::cout << "Enter the maximum time T: ";
    std::cin >> T_max;
    
    std::cout << "Enter the initial value y0: ";
    std::cin >> y0;

    std::cout << "Enter the time-step dt: ";
    std::cin >> dt;

    std::ofstream outfile("rk2.dat");
    if (!outfile.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    double t = 0.0;
    double y = y0;

    while (t <= T_max){
        outfile << t << " " << y << std::endl;
        
        // RK2 method
        double k1 = f(y);
        double k2 = f(y + k1 * dt);
        y += 0.5 * dt * (k1 + k2);
        t += dt;
    }

    outfile.close();
    
    // Calculate exact solution at t = T_max
    double y_exact = exact_solution(T_max, y0);
    double error = fabs(y - y_exact);
    
    std::cout << "Data written to rk2.dat" << std::endl;
    std::cout << "\nAt t = " << T_max << ":" << std::endl;
    std::cout << "Numerical solution (RK2): " << y << std::endl;
    std::cout << "Exact solution: " << y_exact << std::endl;
    std::cout << "Absolute error: " << error << std::endl;
    std::cout << "Relative error: " << (error / y_exact * 100) << "%" << std::endl;
    
    return 0;
}