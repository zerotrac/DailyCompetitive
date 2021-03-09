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
        if (sz[x] < sz[y]) {
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
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n, m, x, y, z;

inline void work() {
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        edges.emplace_back(x - 1, y - 1, z);
    }

    sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
        const auto& [x1, y1, z1] = u;
        const auto& [x2, y2, z2] = v;
        return z1 > z2;
    });

    UF uf(n);
    int bound = INT_MAX;
    for (const auto& [xx, yy, zz]: edges) {
        if (uf.unite(xx, yy)) {
            bound = zz;
        }
    }

    uf = UF(n);
    vector<tuple<int, int, int>> candidates;
    sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
        const auto& [x1, y1, z1] = u;
        const auto& [x2, y2, z2] = v;
        return z1 < z2;
    });
    for (const auto& [xx, yy, zz]: edges) {
        if (zz >= bound && uf.unite(xx, yy)) {
            candidates.emplace_back(xx, yy, zz);
        }
    }

    uf = UF(n);
    LL ans = 0;
    reverse(candidates.begin(), candidates.end());
    for (const auto& [xx, yy, zz]: candidates) {
        int fx = uf.findset(xx);
        int fy = uf.findset(yy);
        if (fx != fy) {
            ans += (LL)zz * uf.sz[fx] * uf.sz[fy];
            uf.unite(xx, yy);
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