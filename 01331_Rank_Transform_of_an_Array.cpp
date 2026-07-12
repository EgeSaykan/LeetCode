#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res = arr;
        int n = arr.size();
        set<int> elems(arr.begin(), arr.end());
        vector vec_elems(elems.begin(), elems.end());
        map<int, int> dict;
        int vec_n = vec_elems.size();

        for (int i = 0; i < vec_n; i++) {
            dict.insert({vec_elems[i], i+1});
        }

        for (int i = 0; i < n; i++) {
            res[i] = dict[arr[i]];
        }
        return res;
    }
};


int main() {
    Solution a = Solution();

    vector<int> arr = {40, 10, 20, 20, 15};

    vector<int> res = a.arrayRankTransform(arr);

    for (int i : res) {
        cout << i << endl;
    }

    return 0;
}