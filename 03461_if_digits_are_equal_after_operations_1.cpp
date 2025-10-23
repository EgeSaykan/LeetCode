#include <iostream>
#include <string>

using namespace std;


class Solution {
public:

    string operation(string s) {
        string result;
        for (size_t i = 0; i < s.length() - 1;i++) {
            result += to_string(((s[i] - '0') + (s[i+1] - '0')) % 10);
        }
        return result;
    }

    bool recursion(string& s) {
        if (s.length() == 2) {
            if (s[0] == s[1]) return true;
            else return false;
        }
        s = operation(s);
        return recursion(s);
    }

    bool hasSameDigits(string s) {
        return recursion(s);
    }
};



int main() {
    Solution solution;

    string a = "2152032";
    int len = solution.hasSameDigits("3902");
    cout << len << endl;
    cout << endl;

    return 0;
}