#include<string>
#include<iostream>
#include <algorithm> 

using namespace std;

class Solution1 {
public:

    void remove(string& s) {
        if (s.size() > 0) {s.pop_back();}
    }

    void add(string& s, char& c) {
        s += c;
    }

    void duplicate(string& s) {
        s += s;
    }


    string processStr(string s) {
        string result;
        while (s.size() > 0) {
            char c = s[0];
            s.erase(0, 1);

            if (96 < c && c < 123) {add(result, c);}
            else if (c == '*') {remove(result);}
            else if (c == '#') {duplicate(result);}
            else if (c == '%') {reverse(result.begin(), result.end());}

        }
        return result;
    }
};



int main() {
    Solution1 solution;

    string a = "o#avw#eoom";
    string result = solution.processStr(a);
    cout << result << endl;
    cout << result[8] << endl;
    cout << endl;

    return 0;
}