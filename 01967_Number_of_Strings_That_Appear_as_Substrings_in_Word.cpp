
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (string s : patterns) {
            if (word.contains(s)) count++;
        }
        return count;
    }
};

int main() {
    Solution sol = Solution();

    vector<string> patterns = {"a", "abc", "bc"};
    string word = "abc";

    int result = sol.numOfStrings(patterns, word);
    cout << "Number of Strings That Appear as Substrings in Word: " << result << endl;

    return 0;
}