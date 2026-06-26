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
        if (a.size() > b.size()) { 
            en = a.size()-1;
            be = en - b.size();
        }
        // int end = 

        // // reverse(a.begin(), a.end());
        // // reverse(b.begin(), b.end());
        bool carry = false;
        for (int i = en; i > be; i--) {
            if ()
        }

        return res;
    }
};


int main() {
    Solution a = Solution();

    string s1 = "123456";
    string m = "dddd";
    string s2 = "123456789";

    string res = a.addBinary(s1, s2);

    cout << res << endl;

    return 0;
}