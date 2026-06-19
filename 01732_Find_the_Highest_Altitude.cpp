#include<iostream>
#include<vector>
#include<numeric>
#include<execution>
#include<random>

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
        
        int binS(vector<int>& gain, int prevSum = -50, int start = -50, int end = -50) {
            int max = 0;
            if (prevSum == -50) {
                prevSum = reduce(execution::par, gain.begin(), gain.end(), 0LL);
                start = 0;
                end = gain.size() - 1 ;
            }
            if (start >= end) {
                return reduce(execution::par, gain.begin(), end+1, 0LL);
            }

            int halfSum = reduce(execution::par, gain.begin(), gain.begin() + (end>>1), 0LL);

            if ((halfSum<<1) > prevSum) {
                return bins(gain, halfSum, start, (start + end)>>1);
            }
            return max;
        }



};

int main() {
    Solution a = Solution();
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> dist(-100, 100);

    int n = 10;
    vector<int> nums(n);
    
    int naiveM = a.naive(nums);
    int binS = a.binS(nums);


    cout << endl;

    return 0;
}