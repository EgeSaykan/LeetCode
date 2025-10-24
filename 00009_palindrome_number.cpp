#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long_x = static_cast<long>(x);
        long temp_x = long_x;
        long reversed_x = 0;
        while (temp_x > 0) {
            reversed_x *= 10;
            temp_x = temp_x / 10;
            reversed_x += temp_x % 10;
        }
        return (long_x == reversed_x);
    }
};


int main() {
    Solution solution;
    int len = solution.isPalindrome(1234567899);
    cout << len << endl;
    cout << endl;

    return 0;
}