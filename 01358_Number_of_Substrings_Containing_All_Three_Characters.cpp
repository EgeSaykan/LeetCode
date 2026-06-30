#include<string>
#include<iostream>

using namespace std;


class Solution {
private:
    int abcLocation[3] = {-1, -1, -1}; // a, b, c
    int beginingOfLastMinimal = -1;
    int triple = 3;

    int combinatonCount(int n1, int n2) {
        return (n1+1)*(n2+1);
    }

    int tripleMin(int* arr) {
        return min(arr[0], min(arr[1], arr[2]));
    }
    int tripleMax(int* arr) {
        return max(arr[0], max(arr[1], arr[2]));
    }

    int minMaxDiff() {
        return tripleMax(abcLocation) - tripleMin(abcLocation) + 1;
    }

public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i] - 97;
            if (abcLocation[c] == -1) {
                abcLocation[c] = i;
                triple--;
                if (!triple) {
                    beginingOfLastMinimal = tripleMin(abcLocation);
                    abcLocation[c] = i;
                    count += combinatonCount(beginingOfLastMinimal, n - i - 1); 
                }
            }
            else {
                if (abcLocation[c] == beginingOfLastMinimal) {
                    abcLocation[c] = i;
                    const int secondmin = tripleMin(abcLocation);
                    count += combinatonCount(secondmin-beginingOfLastMinimal - 1, n - i - 1); 
                    beginingOfLastMinimal = secondmin;
                }
                abcLocation[c] = i;

            }
        }

        return count;
    }
};


int main() {
    cout << endl << endl;

    Solution a = Solution();

    string s = "abcabc";

    int res = a.numberOfSubstrings(s);

    cout << "result: " << res << endl;

    return 0;
}