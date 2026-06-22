#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<limits>

using namespace std;

class Solution {
private:
    map<char, int> counter = {
        {'b', 0},
        {'a', 0},
        {'l', 0},
        {'o', 0},
        {'n', 0}
    };
    map<char, int> dict = {
        {'b', 1},
        {'a', 1},
        {'l', 2},
        {'o', 2},
        {'n', 1}
    };

public:
    int maxNumberOfBalloons(string text) {
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
    int num = a.maxNumberOfBalloons("nuhloonbaluh");
    cout << num << endl;
    return 0;
}