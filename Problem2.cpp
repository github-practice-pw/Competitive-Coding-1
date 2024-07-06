/*
 *                    Find the missing number in the sorted array
 *
 * Brute force approach would be to linearly go through the array and then figure out
 * what is the missing number.
 * Here, the solution I came up with is this, here the time complexity is O(N) and Space is O(1) :
 * 
 * int findMissingNumberBruteForce(const std::vector<int>& nums) {
    int n = nums.size() + 1; // Because one number is missing, the original length would be size + 1

    // Loop through the expected sequence
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    // If no discrepancy found in the loop, the missing number is the last one
    return n;
}
 * To get a better time complexity, the best way we can do it is using a search algorithm.
 * I used binary search since the input mentioned here is a sorted array.
 * We basically can use a divide and conquer method over the sorted array to get the desired
 * number that is missing.
 *
 * Time complexity using this is O(logN) to the base 2; Since here we keep dividing the sorted
 * array into two halves until right becomes greater than left.
 * Space complexity is O(1) since we did not use any extra data structure.
 */
#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int> nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left)/2; // To avoid integer overflow;

        if (nums[mid] == mid+1) { 
            left = mid + 1; // Value lies in the right half
        } else { 
            right = mid- 1; // Value lies in the left half
        }
    }

    return left + 1;
}

int main() {

    vector<int> nums;
    
    // My compiler is old and does not support direct initiallization of
    // vector for some reason. Hence manually had to add the values.

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);


    int answer = missingNumber(nums);

    cout << "The missing value is " << answer << endl;

    return answer;
}