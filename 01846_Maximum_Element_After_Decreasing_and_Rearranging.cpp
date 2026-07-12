#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        map<int, int> elements;
        for (int c : arr) {
            if (elements.contains(c)) {
                elements[c]++;
            }
            else {
                elements[c] = 1;
            }
        }

        int current = 0;
        for (auto a : elements) {
            if (a.second - 1 >= a.first - a.second) { current = a.first; }
            else {
                current += a.second;
            }
        }
        return current;
    }
};

int main() {
    Solution sol = Solution();

    vector<int> arr = {2, 2, 1, 2, 1};

    int result = sol.maximumElementAfterDecrementingAndRearranging(arr);
    cout << "Maximum Element After Decreasing and Rearranging: " << result << endl;

    return 0;
}