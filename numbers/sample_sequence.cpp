/*

   This program explores the fibonacci concept however there is a modification to the traditional function in that instead of summing the last 2 numbers of a sequence it instead sums 3 numbers; hence the name 'tri'bonacci.

   This idea was discovered on an online forum and the objective is to re-create a fibonacci function that given a signature array/list, returns the first n elements - signature included of the so seeded sequence. Both the sequence and the n value are provided by the user via a prompt. 

   Some examples of potential results:
   An input of [1, 1, 1] would return a sequence of [1, 1 ,1, 3, 5, 9, 17, 31, ...]
   An input of [0, 0, 1] would return a sequence of [0, 0, 1, 1, 2, 4, 7, 13, ...]

*/
#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
	std::vector<int> result = signature;

	if (n == 0) { // return an empty array if there is no sequence
		return {};
	} else if (n <= 3) { // there is a 3 number minimum for the signature
		return std::vector<int>(signature.begin(), signature.begin() + n);
	}

	result.reserve(n); // reserve space to avoid frequent reallocations

	for (int i = 3; i < n; ++i) { // run the tribi sequence
		int next_value = result[i - 1] + result[i - 2] + result[i - 3];
		result.push_back(next_value);
	}

	return result;
}

int main() {
	std::vector<int> signature(3);
	int n;

	std::cout << "Enter the signature (3 integers separated by spaces): ";
	std::cin >> signature[0] >> signature[1] >> signature[2];

	std::cout << "Enter the value of n: ";
	std::cin >> n;

	std::vector<int> sequence = tribonacci(signature, n);

	for (int num : sequence) {
		std::cout << num << " ";
	}

	std::cout << "\n";

	return 0;
}

