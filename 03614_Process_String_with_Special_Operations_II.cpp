#include<iostream>
#include<string>
#include<algorithm>
#include<variant>
#include<vector>
#include <cmath>

using namespace std;

class Solution {
public:

    void remove(long long& k, long long& len) {
        if (k >= len)
            k++;
    }

    void add(long long& k, long long& len) {
        if (k < len)
            k--;
    }

    void duplicate(long long& k, long long& len) {
        if (k > (len>>1)-1)
            k -= (len)>>1;
    }

    void reverseK(long long& k, long long& len) {
        if (k <= (len - 1))
            k = len - k - 1;
        // else if (k < (len -1 >> ""))
        //     k = 
    }

    
    void removePre(string& s) {
        size_t char_count = 0;
        size_t i = 0;
        while (i < s.size()) {
            char c = s[i];
            if (c == '*' && char_count > 0) 
                char_count--;
            else if ('a' <= c && c <= 'z') 
                char_count++;
            else if (c == '#')
                char_count <<= 1;
            if (char_count <= 0) {
                s.erase(0,i+1);
                i = 0;
            }
            else
                i++;
        }
    }

    char processStr(string s, long long k) {
        removePre(s);

        vector<long long> lengths;
        long strLen = 0;
        long long len = 0;
        string copyOfOld;
        for (char c : s) {
            if ('a' <= c && c <= 'z') { len++; strLen++; copyOfOld += c; }
            else if (c == '*' && len > 0) { len--; }
            else if (c == '#') { len <<= 1; }
            lengths.push_back(len);
        }
        if (k >= len) return '.';


        for (long i = s.size()-1; i >= 0; i--) {
            char c = s[i];
            long long currLen = lengths.back();
            lengths.pop_back();
            if ('a' <= c && c <= 'z') { }
            else if (c == '*') { remove(k, currLen); }
            else if (c == '#') { duplicate(k, currLen); }
            else if (c == '%') { reverseK(k, currLen); }

        }
        return copyOfOld[k];
    }
};


int main() {
    auto a = Solution();

    string s = "hell#";
    // s = "ca#ke";
    s = "ab#cd";
    s = "*sfvxufzyj";
    s = "%#*gm#xib%";
    // s = "abcdefg#hl#mn";
    s = "l**c##uw#dgr##dkq%oy*wch%#p#yjd#sx####%dcknmoxh##wspv#%eh####n#z#%%*n*#%#fz%nq%%qkkl%eh#pl#%#%%%##ujffil%#o#luq%g###lyl##u%ut#e#j##%%nszcf##%##%lws#akr%b*###n*sp%xu%yl%ye%#%%h%a%%mc%%%%ktroomm%u%%%%s%a%%gurb%%zv%%%%wh%%csi%asw%%%cu**%*%**f**nc**lw%o%mrbp*%%%%nl%ghuc%r*%%*e%%rth%ba%**%%%%%vqd%x%t%c%quf%qm%ac%%%*p%dxr*mmq%%%*x%gvil%a%t%*ow*imtid%g%**%%%uoe%i%cayv%%%r%f%%w%%%lg%%%fhbd%%%i%%*%z%%pu%cr%aw%z%vl%ao%xptk*kvl%j%xb%qql%%l%bg%iwrhlv%*%%q%d%v%*%v%*r**us%u*pvorej%x%%%a%%%%%%*%qff*%c%%%*%xw%%g%**mr%s%a%x%z%%b%q%nlkwl%%j*%%zs*js%ft%i%plt";
    // s = "ab%*cd%ef";
    long long k = 244556;
    // long long k = 6;

    char c = a.processStr(s, k);
    cout << c << endl;

    // int a = 6;
    // cout << a << endl;

    // a >>= 1;
    // cout << a << endl;


    return 0;
}