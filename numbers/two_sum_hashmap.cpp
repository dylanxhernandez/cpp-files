/*
    This example is a potential solution for a sample problem shown below:

    Write a function that takes an array of numbers and a target number. It should find two different items in the array that, when added together, give the target value. The indices of these items should then be returned in a list like so: (index1, index2).

    It is possible to solve this problem using a hashmap to keep track of the numbers. We achieve this by doing the following:

    - Create an unordered_map called num_indices to store the numbers and their corresponding indices.
    - Iterate through the input vector numbers using a for loop.
    - For each number in the vector, calculate its complement by subtracting it from the target.
    - Check if the complement is already in the num_indices map. If it is, that means you've found a pair of numbers that add up to the target, so return the indices of these two numbers in a std::pair.
    - If the complement is not in the map, add the current number to the map with its index.
    - If the loop completes without finding a valid pair, return a dummy pair (0, 0) to indicate that no solution was found.

*/
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    std::unordered_map<int, std::size_t> num_indices;

    for (std::size_t i = 0; i < numbers.size(); ++i) {
        int complement = target - numbers[i];

        if (num_indices.find(complement) != num_indices.end()) {
            // Found a pair that sums to the target
            return {num_indices[complement], i};
        }

        num_indices[numbers[i]] = i;
    }

    // No valid solution, return a dummy pair
    return {0, 0};
}

