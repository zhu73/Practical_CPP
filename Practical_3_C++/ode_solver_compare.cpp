#include <iostream>
#include <fstream>
#include <cmath>

double f(double y) {
    return sqrt(y);
}

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

    std::ofstream outfile("ode_comparison.dat");
    if (!outfile){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    double t = 0.0;
    double y = y0;

    // Write header
    outfile << "# t numerical exact difference" << std::endl;

    while (t <= T_max){
        double y_exact = exact_solution(t, y0);
        outfile << t << " " << y << " " << y_exact << " " << fabs(y - y_exact) << std::endl;
        
        // Euler method update
        y += dt * f(y);
        t += dt;
    }

    outfile.close();
    std::cout << "Data written to ode_comparison.dat" << std::endl;
    return 0;
}