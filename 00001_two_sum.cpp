#include <vector>
#include <iostream>


class Solution {
public:

    size_t max_vec(std::vector<int>& nums) {
        size_t biggest = nums[0];
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > biggest) biggest = nums[i];
        }
        return biggest;
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        size_t biggest = max_vec(nums);
        biggest = (biggest < static_cast<size_t>(target))  ? biggest : static_cast<size_t>(target); 
        std::vector<int> array(++biggest, -1);
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) {
                array[nums[i]] = (int)i;
            }
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) {
                if (array[target - nums[i]] != i && array[target - nums[i]] != -1) {
                    return {(int)i, array[target - nums[i]]};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << result[0] << "  " << result[1];
    return 0;
}