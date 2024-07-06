
/*
 *                    Find the missing number in the unsorted array
 *
 * The only way I could think of doing this is by using the Sum of N natural numbers.
 * 
 * Time complexity using this is O(N) 
 * Space complexity is O(1) since we did not use any extra data structure.
 */
#include <iostream>
#include <vector>

int MissingNumber(const std::vector<int>& nums) {
    int n = nums.size() + 1; // Because one number is missing, the original length would be size + 1
    int total_Sum = n * (n + 1) / 2; // Sum of first n natural numbers
    int sum = 0;

    // Calculate the sum of the array elements
    for (int i = 0; i <= nums.size(); i++) {
        sum += nums[i];
    }

    // The missing number is the difference between the total sum and the array sum
    return total_Sum - sum;
}

int main() {
    std::vector<int> nums;
    // Example array

    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(5);

    int answer = MissingNumber(nums);
    std::cout << "The missing number is: " << answer << std::endl;
    return 0;
}


