#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    --------
    You are given an integer array nums.

    In one operation:
    - Remove the first 3 elements of the array.
    - If fewer than 3 elements remain, remove all of them.

    Repeat the operation until:
    - The array becomes empty, OR
    - The remaining array contains no duplicate elements.

    Return the number of operations required.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        int operations = 0;

        // 'start' represents how many elements have been removed
        int start = 0;

        // Continue while elements are still present
        while (start < n) {

            unordered_set<int> seen;
            bool hasDuplicate = false;

            // Check duplicates in the remaining array
            for (int i = start; i < n; i++) {
                if (seen.count(nums[i])) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(nums[i]);
            }

            // If no duplicates are found, stop
            if (!hasDuplicate) {
                break;
            }

            // Perform one operation (remove first 3 elements logically)
            operations++;
            start += 3;
        }

        return operations;
    }
};

/*
    Example:
    --------
    Input:  nums = [3, 8, 3, 6, 5, 8]

    Operation 1:
    Remaining = [3, 8, 3, 6, 5, 8] -> duplicates exist
    Remove first 3 -> [6, 5, 8]

    Remaining array has all unique elements
    Output = 1
*/
