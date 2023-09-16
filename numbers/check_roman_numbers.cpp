/*

   This program was written for fun. The objective is to collect user input which is meant to be in the form of Roman numerals.

   The user can convert a sequence of Roman numberals into an actual decimal number. Invalid input resets the program and will wait for valid input.

*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Define the Roman numeral values globally
unordered_map<char, int> romanValues = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

// Function to verify if the input contains valid Roman numeral characters
bool isValidRoman(string input) {
    for (char c : input) {
        if (romanValues.find(c) == romanValues.end()) {
            return false;
        }
    }
    return true;
}

int solution(string roman) {
    int result = 0;
    int prevValue = 0;  // Initialize the previous value as 0

    // Iterate through the Roman numeral from right to left
    for (int i = roman.length() - 1; i >= 0; i--) {
        // Get the value of the current Roman numeral character
        int currentValue = romanValues[roman[i]];

        // If the current value is less than the previous value, subtract it
        if (currentValue < prevValue) {
            result -= currentValue;
        }
        // Otherwise, add it to the result
        else {
            result += currentValue;
        }

        // Update the previous value for the next iteration
        prevValue = currentValue;
    }

    return result;
}

int main() {
    string input;
    
    // Ask the user for input and validate it
    do {
        cout << "Enter a Roman numeral: ";
        cin >> input;
    } while (!isValidRoman(input));

    int result = solution(input);
    cout << "Result: " << result << endl;
    
    return 0;
}

