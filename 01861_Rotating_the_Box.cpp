#include <iostream>
#include <vector>

using namespace std;



void applyGravity(vector<vector<char>>& boxGrid) {
    size_t m = boxGrid.size();
    size_t n = boxGrid[0].size();
    for (int row = m-1; row >= 0; row--) {
        for (size_t col = 0; col < n; col++) {
            auto& c = boxGrid[row][col];
            if (c == '*') {continue;}
            if (c == '#') {continue;}
            if (c == '.') {
                for (int up = row; up >= 0; up--) {
                    auto& newC = boxGrid[up][col];
                    if (newC == '*') {break;}
                    if (newC == '#') {
                        newC = '.';
                        c = '#';
                        break;
                    }
                    if (newC == '.') {continue;}
                }
            }
        }
    }
}

void transpose(vector<vector<char>>& boxGrid) {
    size_t m = boxGrid.size();
    size_t n = boxGrid[0].size();
    vector<vector<char>> transposed(n, vector<char>(m, '0'));
    for (int row = m-1; row >= 0; row--) {
        for (size_t col = 0; col < n; col++) {
            transposed[col][row] = boxGrid[row][col];
        }
    }
    boxGrid = transposed;
}

vector<vector<char>> rotateTheBox(vector<vector<char>> boxGrid) {
    size_t m = boxGrid.size();
    size_t n = boxGrid[0].size();
    transpose(boxGrid);
    applyGravity(boxGrid);
    return boxGrid;
}

int main() {
    vector<vector<char>> boxGrid = {{'#', '.', '#'}};
    for (auto row : boxGrid) {
        for (auto c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}