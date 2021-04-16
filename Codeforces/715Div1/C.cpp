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
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (x > y) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }

    int getcomp(int x) {
        return findset(x);
    }

    int getsize(int x) {
        return sz[getcomp(x)];
    }
};


int n, m, x, y, z;
vector<vector<pair<int, int>>> g;
vector<tuple<int, int, int>> edges;
int cnt[200010];

inline void work() {
    cin >> n >> m;
    g.resize(n + 1);
    int xorsum = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        edges.emplace_back(x, y, z);
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
        xorsum ^= z;
    }
    sort(edges.begin(), edges.end(), [](const auto& p, const auto& q) {
        return get<2>(p) < get<2>(q);
    });

    UF uf(n + 1);

    vector<int> ccs = {1};

    for (int u = 2; u <= n; ++u) {
        for (const auto& [v, _]: g[u]) {
            if (v > u) {
                continue;
            }
            int pv = uf.getcomp(v);
            ++cnt[pv];
        }

        vector<int> nxtccs;
        for (auto& v: ccs) {
            if (cnt[v] < uf.getsize(v)) {
                uf.unite(v, u);
            }
            else {
                nxtccs.push_back(v);
            }
        }

        for (auto& v: ccs) {
            cnt[v] = 0;
        }

        nxtccs.push_back(uf.getcomp(u));
        ccs = move(nxtccs);
    }

    LL ss = (LL)n * (n - 1) / 2 - m;

    if (uf.getsize(1) == n) {
        if (ss > n - 1) {
            cout << "0\n";
        }
        else {
            if (!m) {
                cout << "0\n";
            }
            else {
                cout << min(xorsum, get<2>(edges[0])) << "\n";
            }
        }
        return;
    }

    bool need_replace = (ss == n - (uf.comp_cnt - 1));
    LL ans = (need_replace ? xorsum : 0);

    UF ufo(n + 1);
    for (const auto& [xx, yy, zz]: edges) {
        if (ufo.unite(xx, yy)) {
            if (uf.connected(xx, yy)) {
                if (need_replace && zz < xorsum) {
                    need_replace = false;
                    ans -= xorsum - zz;
                }
            }
            else {
                uf.unite(xx, yy);
                ans += zz;
            }
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