#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<limits>

using namespace std;

class Solution {
private:
    map<char, int> counter = {
    };
    map<char, int> dict = {
    };

public:
    int rearrangeCharacters(string text, string target) {
        for (char c : target) {
            if (dict.contains(c)) {
                dict[c] += 1;
            }
            else {
                dict.insert({c, 1});
                counter.insert({c, 0});
            }
        }
        for (char c : text) {
            if (counter.contains(c)) {
                counter[c] += 1;
            }
        }
        int min = INT_MAX;
        for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
            char c = itr->first;
            counter[c] /= dict[c];
            if (counter[c] < min) min = counter[c];
        }
        return min;
    }
};

int main() {
    auto a = Solution();
    int num = a.rearrangeCharacters("nuhloonbaluh", "baloon");
    cout << num << endl;
    return 0;
}