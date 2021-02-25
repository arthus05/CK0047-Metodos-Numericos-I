#include <iostream>
#include <cmath>
const double eulerConstant = std::exp(1.0);

//limite d - 0.7

double amplitude, displacement;

template <typename T>
T calculate_function(T amplitude, T displacement)
{
    //f(d) = a*(e^d) - 4*(d^2)
    return (amplitude * (std::pow(eulerConstant, displacement)) - 4 * (std::pow(displacement, 2.0)));
}

double calculate_next_root(double previousRoot, double currentRoot, double amplitude)
{
    double nextRoot =
        currentRoot - (calculate_function<double>(amplitude, currentRoot)) /
                          ((calculate_function<double>(amplitude, currentRoot) - calculate_function<double>(amplitude, previousRoot)) /
                           (currentRoot - previousRoot));

    return nextRoot;
}

double secant_method(double amplitude, double initialDisplacement) {
    double upperLimit = 0.7, previousRoot = initialDisplacement, currentRoot = previousRoot + 1;
    for(int i = 0; i < 3; ++i) {
        std::cout << "Current Root: " << currentRoot;
        double nextRoot = calculate_next_root(previousRoot, currentRoot, amplitude);
        previousRoot = currentRoot; currentRoot = nextRoot;

    }

}

int main()
{
    double amplitude = 1.0, initialDisplacement = 0.5, precision = 0.0001;
    double result = secant_method(amplitude, initialDisplacement);
    std::cout << result;
    return 0;
}
