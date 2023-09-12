#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

bool is_square(int n) {
    if (n < 0) {
        return false; // Negative numbers cannot be perfect squares
    }

    int squareRoot = static_cast<int>(std::sqrt(n));
    return squareRoot * squareRoot == n;
}

int main() {
    std::string input;
    std::cout << "Enter a series of numbers separated by spaces: ";
    std::getline(std::cin, input);

    std::istringstream inputStreamHelper(input);
    std::vector<int> userCases;
    int num;

    while (inputStreamHelper >> num) {
        userCases.push_back(num);
    }

    if (userCases.empty()) {
        std::cout << "Invalid input. Please enter at least one number." << std::endl;
        return 1;
    }

    std::cout << "Results:" << std::endl;
    for (int i = 0; i < userCases.size(); i++) {
        bool result = is_square(userCases[i]);
        std::cout << userCases[i] << " => " << (result ? "true" : "false") << std::endl;
    }

    return 0;
}

