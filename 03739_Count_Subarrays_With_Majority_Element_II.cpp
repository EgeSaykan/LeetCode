#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long answer = 0;
        long long counter = 0;
        int pos = n;
        long long apartment[n*2+1];
        for (long long&x : apartment) x = 0;
        apartment[n] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                counter += apartment[pos];
                pos++;
                apartment[pos]++;
            }
            else {
                pos--;
                counter -= apartment[pos];
                apartment[pos]++;
            }
            answer += counter;
        }

        return answer;
    }
};

int main() {
	Solution a = Solution();
	vector<int> nums = {1, 1, 2, 5, 1, 6, 1};
	int target = 1;
	long long ans = a.countMajoritySubarrays(nums, target);
	cout << ans << endl;
	
	return 0;
}
