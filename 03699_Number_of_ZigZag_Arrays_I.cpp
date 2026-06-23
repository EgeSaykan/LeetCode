#include<iostream>
#include<math.h>
#include<vector>

using namespace std;


class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int numberRange = r - l + 1;
        unsigned long long m = 0;
        vector<unsigned long long> prev(numberRange, 1), cur(numberRange), prefix(numberRange);
        unsigned const long long MOD = 1000000007;
        for (int i = 1; i < n; i++) {
            prefix[0] = prev[0];
            for (int j = 1; j < numberRange; j++) {
                prefix[j] = (prefix[j - 1] + prev[j]) % MOD;
            }

            if (i % 2 == 1) {
                long long total = prefix[numberRange - 1];

                for (int a = 0; a < numberRange; a++) {
                    cur[a] = (total - prefix[a] + MOD) % MOD;
                }
            }
            else {
                cur[0] = 0;

                for (int a = 1; a < numberRange; a++) {
                    cur[a] = prefix[a - 1];
                }
            }

            prev = cur;
        }
        for (int i = 0; i < numberRange; i++) m+=cur[i];
        m <<= 1;
        m %= 1000000007;

        return m;
    }
};

int main() {

    int n = 12, l = 42, r = 144;
    Solution a = Solution();
    int result = a.zigZagArrays(n, l, r);

    cout << "result: " << result << endl;

    return 0;
}