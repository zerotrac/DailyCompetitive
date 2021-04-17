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

int n;
int a[200010], b[200010];

inline int get(const vector<pair<int, int>>& p, const vector<pair<int, int>>& q) {
    int ptr = 0;
    int right = 0;
    int ans = 0;
    for (const auto& [x, y] : q) {
        while (ptr < p.size() && p[ptr].first <= x) {
            right = max(right, p[ptr].second);
            ++ptr;
        }
        ans = max(ans, min(right, y) - x);
    }
    return ans;
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int>> p, q;
    LL tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > b[i]) {
            p.emplace_back(b[i], a[i]);
        }
        else {
            q.emplace_back(a[i], b[i]);
        }
        tot += abs(a[i] - b[i]);
    }

    if (p.empty() || q.empty()) {
        cout << tot << "\n";
    }
    else {
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        int dec = max(get(p, q), get(q, p));
        cout << tot - dec * 2 << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}