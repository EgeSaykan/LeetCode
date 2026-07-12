#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        

        return false;
    }
};


int main() {
    Solution a = Solution();

    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;

    bool res = a.findSafeWalk(grid, health);

    cout << "result: " << res << endl;

    return 0;
}