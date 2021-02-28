#include <iostream>
#include <iomanip>
#include <fstream>
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

int k;
int cnt[10];
string s, t;

inline int get(const string& s) {
    unordered_map<int, int> cnt;
    for (char ch: s) {
        ++cnt[ch - '0'];
    }
    int ret = 0;
    for (int i = 1; i <= 9; ++i) {
        ret += pow(10, cnt[i]) * i;
    }
    return ret;
}

inline void work() {
    cin >> k;
    for (int i = 1; i <= 9; ++i) {
        cnt[i] = k;
    }

    cin >> s >> t;
    for (int i = 0; i < 4; ++i) {
        --cnt[s[i] - '0'];
        --cnt[t[i] - '0'];
    }

    double ans = 0.;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j && cnt[i] < 2) {
                continue;
            }
            if (!cnt[i] || !cnt[j]) {
                continue;
            }

            s[4] = i + '0';
            t[4] = j + '0';
            int scores = get(s);
            int scoret = get(t);
            if (scores > scoret) {
                if (i == j) {
                    ans += (LL)cnt[i] * (cnt[i] - 1);
                }
                else {
                    ans += (LL)cnt[i] * cnt[j];
                }
            }
        }
    }

    LL rest = k * 9 - 8;
    ans /= (LL)rest * (rest - 1);
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}