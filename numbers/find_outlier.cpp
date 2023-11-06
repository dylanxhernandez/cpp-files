#include <vector>

/*
    You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
    
    The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

    You can solve this problem by iterating through the array and checking the parity of the first three numbers to determine whether the array is primarily even or odd. 

    Once you've identified the majority, you can find the outlier based on that information. 
*/

int FindOutlier(std::vector<int> arr) {
    int evenCount = 0; // Count of even numbers in the first three elements
    int oddCount = 0;  // Count of odd numbers in the first three elements

    // Count the parity of the first three elements
    for (int i = 0; i < 3; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Determine the majority parity based on the counts
    bool isMajorityEven = evenCount > oddCount;

    // Iterate through the array to find the outlier based on the majority parity
    for (int num : arr) {
        if (isMajorityEven && num % 2 != 0) {
            return num; // Found an odd number in an even-majority array
        } else if (!isMajorityEven && num % 2 == 0) {
            return num; // Found an even number in an odd-majority array
        }
    }

    // Return a default value if no outlier is found (you can handle this case differently if needed)
    return 0;
}

