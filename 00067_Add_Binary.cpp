#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



class Solution {
private:
    void removeLeadingZeros(string& a) {
        while (a.size() > 0) {
            if (a[0] == '0') a.erase(0, 1);
            else break;
        }
    }
public:
    string addBinary(string a, string b) {
        auto a_count = a.find('1');
        auto b_count = b.find('1');
        if (a_count == std::string::npos && b_count == std::string::npos) return "0";
        else if (a_count == std::string::npos) return b;
        else if (b_count == std::string::npos) return a;
        else if (a == b) return a + "0";
        string res = "";
        string& bigger  = (a.size() >= b.size()) ? a : b;
        string& smaller = (a.size() >= b.size()) ? b : a;
        const int small_size = smaller.size();
        const int bigger_size = bigger.size();
        int diff = bigger_size - small_size;
        unsigned int carry = 0;
        for (int i = small_size-1; i >= 0; i--) {
            int add = carry + (bigger[i + diff] & 1) + (smaller[i] & 1);
            if (add == 3) {
                carry = 1;
                res = "1" + res;
            }
            else if (add == 2) {
                carry = 1;
                res = "0" + res;
            }
            else if (add == 1) {
                carry = 0;
                res = "1" + res;
            }
            else if (add == 0) {
                carry = 0;
                res = "0" + res;
            }
        }
        if (carry == 0) return bigger.substr(0, diff) + res;
        if (diff == 0) return "1" + res;
        while (diff >= 0) {
            --diff;
            const char c = bigger[diff];
            
            if (c == 48) {
                res = bigger.substr(0, diff) + "1" + res;
                break;
            }
            if (diff == 0) {
                res = "10" + res;
                break;
            }
            res = "0" + res;
        }
        return res;
    }
};



int main() {
    Solution a = Solution();

    string s1 = "1010";
    string m = "dddd";
    string s2 = "1011";

    string res = a.addBinary(s1, s2);

    cout << res << endl;

    return 0;
}