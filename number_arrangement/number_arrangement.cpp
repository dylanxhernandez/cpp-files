/* 
 
   The objective of this program is to make a function that can take any non-negative number as an argument and return it with its digits arranged in a new order. 

   This new arrangement is in descending order with the highest number at the start and the lowest number at the end. This program will prompt the user to enter any sequence of numbers and the program will perform a sort. 

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

uint64_t rearrangeDigitsDescending(uint64_t num) {
    // convert the number to a string to work with its digits
    std::string numStr = std::to_string(num);

    // convert the string to a vector of characters for sorting
    std::vector<char> digitsVec(numStr.begin(), numStr.end());

    // sort the digits in descending order
    std::sort(digitsVec.rbegin(), digitsVec.rend());

    // convert the sorted digits back to a string
    std::string resultStr(digitsVec.begin(), digitsVec.end());

    // convert the string back to uint64_t
    return std::stoull(resultStr);
}

int main() {
	// get input from user
	uint64_t input;
    std::cout << "Enter an number value: ";
	std::cin >> input;
    
	// calculate the result
	uint64_t result = rearrangeDigitsDescending(input);

	// print results
	std::cout << "Original number: " << input << std::endl;
    std::cout << "Number with digits in descending order: " << result << std::endl;

    return 0;
}

