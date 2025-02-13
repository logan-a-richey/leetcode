// 04_find_median_of_two_sorted_arrays.cpp
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// brute force method: merge the two lists, sort the merged list, return the median
/*
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& a, std::vector<int>b ){
        int m = a.size(), n = b.size(), i = 0, j = 0, k = 0;
        std::vector<int> merged(m + n);

        // Merge both sorted arrays in O(m + n)
        while (i < m && j < n) 
            merged[k++] = (a[i] < b[j]) ? a[i++] : b[j++];

        while (i < m) merged[k++] = a[i++];
        while (j < n) merged[k++] = b[j++];

        // Find median
        int mid = (m + n) / 2;
        return ((m + n) % 2) ? merged[mid] : (merged[mid - 1] + merged[mid]) / 2.0;
    }
};
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
        // Ensure the smaller array is used for binary search
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int l = 0, r = m;

        while (l <= r) {
            int x = (l + r) / 2;
            int y = (m + n + 1) / 2 - x; // The number of elements on the left side

            // Handle boundary cases with min and max of the partitions
            int L1 = (x == 0) ? std::numeric_limits<int>::min() : a[x - 1];
            int R1 = (x == m) ? std::numeric_limits<int>::max() : a[x];
            int L2 = (y == 0) ? std::numeric_limits<int>::min() : b[y - 1];
            int R2 = (y == n) ? std::numeric_limits<int>::max() : b[y];

            // Check if the partitions are correct
            if (L1 <= R2 && L2 <= R1) {
                // Odd total length: max of left elements
                // Even total length: average of the max of left and min of right
                return (m + n) % 2 ? std::max(L1, L2) : (std::max(L1, L2) + std::min(R1, R2)) / 2.0;
            } else if (L1 > R2) {
                r = x - 1; // Partition too far right in array 'a'
            } else {
                l = x + 1; // Partition too far left in array 'a'
            }
        }
        return 0.0; // Should never reach here
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};

    double res = sol.findMedianSortedArrays(nums1, nums2); 
    std::cout << "Median: " << res << std::endl; // Output: 2.5
    return 0;
}

