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

int n, m, k, x, y, z;

inline void work() {
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges;
    int closest = INT_MAX;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        edges.emplace_back(x - 1, y - 1, z);
        closest = min(closest, abs(z - k));
    }
    sort(edges.begin(), edges.end(), [&](const auto& u, const auto& v) {
        return get<2>(u) < get<2>(v);
    });

    UF uf(n);
    int threshold = 0;
    LL ans = 0;
    for (const auto& [xx, yy, zz]: edges) {
        if (uf.unite(xx, yy)) {
            threshold = zz;
            if (zz > k) {
                ans += zz - k;
            }
        }
    }
    if (threshold >= k) {
        cout << ans << "\n";
    }
    else {
        cout << closest << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}