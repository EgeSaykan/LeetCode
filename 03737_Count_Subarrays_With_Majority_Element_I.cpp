#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int answer = 0;
        int counter = 0;
        int pos = n;
        int apartment[n*2+1];
        for (int&x : apartment) x = 0;
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
	int ans = a.countMajoritySubarrays(nums, target);
	cout << ans << endl;
	
	return 0;
}
