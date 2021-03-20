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

#include <atcoder/convolution>

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

string s, t;


inline void work() {
    cin >> s >> t;
    reverse(t.begin(), t.end());
    vector<int> s0, t0, s1, t1;
    for (char ch: s) {
        s0.push_back(ch - '0');
        s1.push_back((ch - '0') ^ 1);
    }
    for (char ch: t) {
        t0.push_back(ch - '0');
        t1.push_back((ch - '0') ^ 1);
    }
    vector<int> res0 = atcoder::convolution(s0, t1);
    vector<int> res1 = atcoder::convolution(s1, t0);

    int ans = INT_MAX;
    int n = s.size(), m = t.size();
    for (int i = m - 1; i < n; ++i) {
        ans = min(ans, res0[i] + res1[i]);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}