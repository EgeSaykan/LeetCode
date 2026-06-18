#include<iostream>
#include<string>
#include<algorithm>
#include<variant>
#include<vector>
#include <cmath>

using namespace std;

class Solution {
public:

    void remove(long long& k) {
        k++;
    }

    void add(long long& k) {
        k--;
    }

    void duplicate(long long& k, long long& len) {
        k -= (len >> 1);
    }

    void reverseK(long long& k, long long& len) {
        k = len - k - 1;
    }

    char processStr(string s, long long k) {

        vector<long long> lengths;
        long strLen = 0;
        long long len = 0;
        for (char c : s) {
            if ('a' <= c && c <= 'z') { len++; strLen++;}
            else if (c == '*' && len > 0) { len--; }
            else if (c == '#') { len <<= 1; }
            lengths.push_back(len);
            cout << len << " ";
        }
        cout << endl;
        if (k >= len) return '.';

        string copyOfOld = s;
        reverse(s.begin(), s.end());

        for (char c : s) {
            long long currLen = lengths.back();
            lengths.pop_back();
            if ('a' <= c && c <= 'z') {  }
            else if (c == '*') { remove(k); }
            else if (c == '#') { duplicate(k, currLen); }
            else if (c == '%') { reverseK(k, currLen); }
            cout << "k: " << k  << "    c: " << c << "   len: "<< currLen << endl;

        }
        cout << "k: " << k << endl;
        return copyOfOld[k];
    }
};


int main() {
    auto a = Solution();

    string s = "hell#";
    // s = "ca#ke";
    s = "p#m#f#ast#a";
    long long k = 5;

    char c = a.processStr(s, k);
    cout << c;

    // int a = 6;
    // cout << a << endl;

    // a >>= 1;
    // cout << a << endl;


    return 0;
}