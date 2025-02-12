// 01_two_sum.cpp

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target){
        // use unordered_map for O(1) average lookup time
        std::unordered_map<int, int> lookup; 
        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            // if the compliment is map, return their indexes  
            if (lookup.find(compliment) != lookup.end()) {
                return {lookup[compliment], i}; 
            }
            // key: number, value: index of number
            lookup[nums[i]] = i; 
        }
        // handle no solution case
        return {-1, -1};
    }
};

int main(){
    Solution mysol;
    int target = 6;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> res = mysol.twoSum(nums, target);
    std::cout << "[" << res[0] << ", " << res[1] << "]" << std::endl;
    return 0;
}
