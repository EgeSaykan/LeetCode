#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ld = long double;

// Solve linear system A x = b
vector<ld> gaussianSolve(vector<vector<ld>> A, vector<ld> b) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }

    for (int i = 0; i < n; i++) {
        // pivot
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
        }
        swap(A[i], A[pivot]);

        ld div = A[i][i];
        if (fabs(div) < 1e-12) continue;

        for (int j = i; j <= n; j++) A[i][j] /= div;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            ld factor = A[j][i];
            for (int k = i; k <= n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    vector<ld> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = A[i][n];
    }
    return x;
}

// build recurrence coefficients
vector<ld> findCoefficients(const vector<long long>& a, int r) {
    vector<vector<ld>> A(r, vector<ld>(r));
    vector<ld> b(r);

    // we use equations:
    // a[r] ... a[2r-1]
    for (int i = 0; i < r; i++) {
        b[i] = a[r + i];

        for (int j = 0; j < r; j++) {
            A[i][j] = a[r + i - j - 1];
        }
    }

    return gaussianSolve(A, b);
}

// generate sequence
vector<long long> generate(int r, vector<long long> init, int n) {
    vector<long long> seq = init;

    if (n <= seq.size()) {
        seq.resize(n);
        return seq;
    }

    cout << "Coefficients: " << endl;
    vector<ld> c = findCoefficients(init, r);
    for (auto &x : c) {
        cout << x << " ";
    }
    cout << endl;

    for (int i = seq.size(); i < n; i++) {
        ld val = 0;
        for (int j = 0; j < r; j++) {
            val += c[j] * seq[i - j - 1];
        }
        seq.push_back((long long)llround(val));
    }

    return seq;
}

int main() {
    int r = 5, n = 15;

    vector<long long> init = {55, 190, 671, 2353, 8272, 29056, 102091, 358671};

    vector<long long> res = generate(r, init, n);

    cout << "Generated sequence: ";
    for (auto x : res) cout << x << " ";
    cout << "\n";
}