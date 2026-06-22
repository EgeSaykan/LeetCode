#include<iostream>
#include<vector>
#include<numeric>
#include<execution>
#include<random>
#include<chrono>

using namespace std;


class Solution {
    public:
        int naive(vector<int>& gain) {
            int max = 0;
            int pos = 0;
            for (int i : gain) {
                pos += i;
                if (pos > max) max = pos;
            }
            return max;
        }
};

int main() {
    Solution a = Solution();
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-100, 100);

    const int n = 1000;
    vector<int> nums(n);

    for (auto& x : nums) x = dist(rng);

    int max = a.naive(nums);
    cout << max << endl;

    return 0;
}