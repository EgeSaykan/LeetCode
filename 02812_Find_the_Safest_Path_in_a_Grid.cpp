
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();



        vector<vector<int>> thieves;
        int len_thieves = thieves.size();
        int dist[n][n] = {0};

        

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if(grid[r][c] == 1) thieves.push_back({r, c, 1});
            }
        }

        for (auto t : thieves) {
            cout << t[0] << "   " << t[1] << endl;

        }

        int queue = 0;
        while (true) {

            int& rad = thieves[queue][2];
            int& x =   thieves[queue][0];
            int& y =   thieves[queue][1];
            for (int i = 1; i <= rad; i++) {
                if (y - (rad - i) >= 0 && i+x < n) {
                    dist[y - (rad - i)][i] = rad;
                }
                if (y + (rad - i)) < n && i+x < n) {

                }
            

            queue++;
            if (queue == len_thieves) queue = 0;
        }

        // for (auto k : thieves) {
        //     cout << k[0] << "   " << k[1] << endl;
        //     int k0 = k[0];
        //     int k1 = k[1];
        //     for (int r = 0; r < n; r++) {
        //         for (int c = 0; c < n; c++) {
        //             dist[r][c] = min(abs(r - k0) + abs(c - k1), dist[r][c]);
        //         }
        //     }
        // }

        // for (auto k : thieves) {
        //     dist[k[0]][k[1]] = 0;
        // }

        // for (int r = 0; r < n; r++) {
        //     for (int c = 0; c < n; c++) {
        //         cout << dist[r][c] << "  ";
        //     }
        //     cout << endl;
        // }

        // int final[n][n];
        // final[0][0] = 0;
        // for (int r = 1; r < n; r++) final[r][0] = dist[r][0] + dist[r-1][0];
        // for (int c = 1; c < n; c++) final[0][c] = dist[0][c] + dist[0][c-1];
        // for (int r = 1; r < n; r++) {
        //     for (int c = 1; c < n; c++) {
        //         final[r][c] = dist[r][c] + min(dist[r-1][c], dist[r][c-1]);
        //     }
        // }
        // cout << endl;
        // cout << endl;

        // for (int r = 0; r < n; r++) {
        //     for (int c = 0; c < n; c++) {
        //         cout << final[r][c] << "  ";
        //     }
        //     cout << endl;
        // }

        return 0;
    }
};

int main() {
    Solution a = Solution();

    vector<vector<int>> grid = {{0, 1, 0}, {0, 1, 1}, {0, 0, 0}};

    int result = a.maximumSafenessFactor(grid);
    cout << result << endl;
    return 0;
}