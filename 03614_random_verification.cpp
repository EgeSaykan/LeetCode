#include <algorithm>
#include <iostream>
#include <random>
#include <string>

using namespace std;

class Solution1 {
public:
    void remove(string& s) {
        if (s.size() > 0) {
            s.pop_back();
        }
    }

    void add(string& s, char& c) {
        s += c;
    }

    void duplicate(string& s) {
        s += s;
    }

    string processStr(string s) {
        string result;
        while (s.size() > 0) {
            char c = s[0];
            s.erase(0, 1);

            if (96 < c && c < 123) {
                add(result, c);
            } else if (c == '*') {
                remove(result);
            } else if (c == '#') {
                duplicate(result);
            } else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};

class Solution {
public:
    void remove(long long& k, long long& len) {
        if (k >= len) {
            k++;
        }
    }

    void add(long long& k, long long& len) {
        if (k < len) {
            k--;
        }
    }

    void duplicate(long long& k, long long& len) {
        if (k >= (len - 1)) {
            k = len >> 1;
        }
    }

    void reverseK(long long& k, long long& len) {
        if (k <= (len - 1)) {
            k = len - k - 1;
        }
    }

    char processStr(string s, long long k) {
        vector<long long> lengths;
        long long len = 0;
        string copyOfOld;

        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                len++;
                copyOfOld += c;
            } else if (c == '*' && len > 0) {
                len--;
            } else if (c == '#') {
                len <<= 1;
            }
            lengths.push_back(len);
        }

        if (k >= len) {
            return '.';
        }

        reverse(s.begin(), s.end());

        for (char c : s) {
            long long currLen = lengths.back();
            lengths.pop_back();

            if ('a' <= c && c <= 'z') {
                continue;
            } else if (c == '*') {
                remove(k, currLen);
            } else if (c == '#') {
                duplicate(k, currLen);
            } else if (c == '%') {
                reverseK(k, currLen);
            }
        }

        return copyOfOld[k];
    }
};

static string randomTestString(mt19937& rng) {
    static const string alphabet = "abcdefghijklmnopqrstuvwxyz*#%";
    uniform_int_distribution<int> dist(0, static_cast<int>(alphabet.size()) - 1);

    string s;
    s.reserve(10);
    for (int i = 0; i < 10; ++i) {
        s += alphabet[dist(rng)];
    }
    return s;
}

int main() {
    Solution1 oracle;
    Solution subject;

    mt19937 rng(123456789);
    uniform_int_distribution<int> pickIndex;

    int passed = 0;
    int failed = 0;

    for (int i = 0; i < 50; ++i) {
        string s = randomTestString(rng);
        string expectedString = oracle.processStr(s);

        if (expectedString.empty()) {
            cout << "[" << i + 1 << "] " << s << " -> skipped (empty oracle output)\n";
            continue;
        }

        pickIndex = uniform_int_distribution<int>(0, static_cast<int>(expectedString.size()) - 1);
        long long k = pickIndex(rng);

        char expected = expectedString[static_cast<size_t>(k)];
        char actual = subject.processStr(s, k);

        if (expected == actual) {
            ++passed;
            cout << "[" << i + 1 << "] PASS  s=" << s << " k=" << k << " -> " << actual << '\n';
        } else {
            ++failed;
            cout << "[" << i + 1 << "] FAIL  s=" << s << " k=" << k
                 << " expected=" << expected << " actual=" << actual
                 << " oracle=" << expectedString << '\n';
        }
    }

    cout << "\nSummary: passed=" << passed << " failed=" << failed << '\n';
    return failed == 0 ? 0 : 1;
}