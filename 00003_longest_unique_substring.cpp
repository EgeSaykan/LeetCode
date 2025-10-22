#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int numberOfUniqueChars = 0;
        string seen;
        int greatestLength = 0;
        for (char c : s) {
            if (seen.find(c) == string::npos){
                seen += c;
                numberOfUniqueChars++;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            string thisLChars;
            for (int l = 0; l < numberOfUniqueChars; l++) {
                if (thisLChars.find(s[i+l]) == string::npos){
                    thisLChars += s[i+l];
                    if (greatestLength < thisLChars.length()) greatestLength = thisLChars.length();
                    if (thisLChars.length() == numberOfUniqueChars) return numberOfUniqueChars;
                }
                else if (greatestLength < thisLChars.length()) {
                    greatestLength = thisLChars.length();
                    break;
                }
                else break;
                if (i + l + 1 == s.length()) break;
            }
        }
        return greatestLength;
    }
};



int main() {
    Solution solution;

    int len = solution.lengthOfLongestSubstring("pwwkew");
    cout << len << endl;
    cout << endl;

    return 0;
}