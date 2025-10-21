#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map <int, int> u_map;

        for (int i = 0; i < nums.size(); i++) {
            if (u_map.count(target - nums[i]) >= 1) {
                return {u_map[target - nums[i]], i};
            }
            else {
                u_map[nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {5, -75, -25};
    int target = -100;
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << result[0] << "  " << result[1];
    return 0;
}