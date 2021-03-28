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

string s;

inline void work() {
    cin >> s;
    int n = s.size();
    unordered_map<char, vector<int>> pp;
    for (int i = 0; i < n; ++i) {
        pp[s[i]].push_back(i);
    }

    auto count = [&](int l, int r, char ch) -> int {
        if (l > pp[ch].back() || r < pp[ch][0]) {
            return 0;
        }
        auto it1 = lower_bound(pp[ch].begin(), pp[ch].end(), l);
        auto it2 = prev(upper_bound(pp[ch].begin(), pp[ch].end(), r));
        return it2 - it1 + 1;
    };

    char last = '.';
    int pos = n;
    LL ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == s[i + 1]) {
            if (s[i] == last) {
                ans += pos - i - 2 - count(i + 2, pos - 1, s[i]);
            }
            else {
                ans += n - i - 2 - count(i + 2, pos - 1, s[i]);
            }
            last = s[i];
            pos = i;
            --i;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}