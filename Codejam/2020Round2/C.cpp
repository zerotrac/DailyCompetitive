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

int n;
LL x[200], y[200];

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    
    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }
    
    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }
    
    void findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
        }
    }
};

struct dwell {
    int u, v;
    LL du, dv;
    dwell(int _u, int _v, LL _du, LL _dv): u(_u), v(_v), du(_du), dv(_dv) {}
    bool operator< (const dwell& that) const {
        return dv * that.du < that.dv * du;
    }
    bool operator== (const dwell& that) const {
        return dv * that.du == that.dv * du;
    }
};

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<dwell> v;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && (x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]))) {
                v.emplace_back(i, j, x[j] - x[i], y[j] - y[i]);
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        int j = i;
        while (j + 1 < v.size() && v[j + 1] == v[i]) {
            ++j;
        }
        
        UF uf(n);
        for (int k = i; k <= j; ++k) {
            uf.findAndUnite(v[k].u - 1, v[k].v - 1);
        }
        vector<int> group;
        for (int k = 0; k < n; ++k) {
            if (uf.fa[k] == k) {
                group.push_back(uf.sz[k]);
            }
        }
        int sum = 0, odd = 0, cnt1 = 0;
        for (int g: group) {
            if (g > 1) {
                sum += g;
                if (g & 1) {
                    ++odd;
                }
            }
            else {
                ++cnt1;
            }
        }
        ans = max(ans, sum + (odd & 1 ? min(cnt1, 1) : min(cnt1, 2)));
        i = j;
    }
    cout << ans << "\n";
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