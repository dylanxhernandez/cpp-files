#include <vector>

/*
    The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

    maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});

    Result should be 6: {4, -1, 2, 1}

*/

int maxSequence(const std::vector<int>& arr) {
    int maxSum = 0;  // Initialize the maximum sum
    int currentSum = 0;  // Initialize the current sum

    for (int num : arr) {
        currentSum = std::max(num, currentSum + num);  // Calculate the maximum of the current element or the sum including the current element
        maxSum = std::max(maxSum, currentSum);  // Update the maximum sum if the current sum is greater
    }

    return maxSum;
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSequence(arr);
    std::cout << "Maximum sum subarray is: " << result << std::endl;
    return 0;
}

