#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int en = b.size()-1;
        int be = en - a.size();
        int bOffset = 0;
        int aOffset = be+1;
        if (a.size() > b.size()) { 
            en = a.size()-1;
            be = en - b.size();
            aOffset = 0;
            bOffset = be+1;
        }
        unsigned int carry = 0;
        for (int i = en; i > be; i--) {
            int add = (a[i - aOffset] & 1) + (b[i - bOffset] & 1) + carry;
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
        if (carry == 1) {
            if (a.size() > b.size()) {
                for (int i = be; i >= 0; i--) {
                    if (carry == 0) break;
                    if (a[i] == '1') {
                        res = "0" + res;
                        carry = 1;
                    }
                    else {
                        res = "1" + res;
                    }
                }
            }
        }
        

        return res;
    }
};


int main() {
    Solution a = Solution();

    string s1 = "1011101";
    string m = "dddd";
    string s2 = "1011101";

    string res = a.addBinary(s1, s2);

    cout << res << endl;

    return 0;
}