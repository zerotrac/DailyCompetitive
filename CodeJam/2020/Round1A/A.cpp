#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string s[50];
bool status[50];
int n;

inline void work() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    bool pre = true, suf = true;
    string prefix, suffix;
    int rest = n;
    memset(status, true, sizeof(status));
    for (int i = 0; rest; ++i) {
        char ch = '*';
        for (int j = 0; j < n; ++j) {
            if (status[j]) {
                if (s[j][i] == '*') {
                    status[j] = false;
                    --rest;
                }
                else {
                    if (ch == '*') {
                        ch = s[j][i];
                    }
                    else if (ch != s[j][i]) {
                        pre = false;
                        rest = 0;
                        break;
                    }
                }
            }
        }
        if (rest) {
            prefix += ch;
        }
    }
    rest = n;
    memset(status, true, sizeof(status));
    for (int i = 0; rest; ++i) {
        char ch = '*';
        for (int j = 0; j < n; ++j) {
            if (status[j]) {
                // cout << "now = " << s[j][s[j].size() - i - 1] << "\n";
                if (s[j][s[j].size() - i - 1] == '*') {
                    status[j] = false;
                    --rest;
                }
                else {
                    if (ch == '*') {
                        ch = s[j][s[j].size() - i - 1];
                    }
                    else if (ch != s[j][s[j].size() - i - 1]) {
                        suf = false;
                        rest = 0;
                        break;
                    }
                }
            }
        }
        // cout << "ch = " << ch << " " << suf << "\n";
        if (rest) {
            suffix += ch;
        }
    }
    reverse(suffix.begin(), suffix.end());
    if (!pre || !suf) {
        cout << "*\n";
    }
    else {
        string ans = prefix;
        for (int i = 0; i < n; ++i) {
            int l = -1, r = -1;
            for (int j = 0; j < s[i].size(); ++j) {
                if (s[i][j] == '*') {
                    if (l == -1) {
                        l = j;
                    }
                    r = j;
                }
            }
            // cout << "l, r = " << l << " " << r << "\n";
            for (int j = l + 1; j < r; ++j) {
                if (s[i][j] != '*') {
                    ans += s[i][j];
                }
            }
        }
        ans += suffix;
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}