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

int m, n;
string st;

inline void work() {
    cin >> m >> n;
    UF uf(m + n);
    uf.unite(0, m);
    uf.unite(0, m + n - 1);
    uf.unite(m - 1, m);
    uf.unite(m - 1, m + n - 1);
    for (int i = 1; i <= m; ++i) {
        cin >> st;
        for (int j = 1; j <= n; ++j) {
            if (st[j - 1] == '#') {
                uf.unite(i - 1, m + j - 1);
            }
        }
    }

    unordered_set<int> rr, cc;
    for (int i = 0; i < m; ++i) {
        rr.insert(uf.findset(i));
    }
    for (int i = m; i < m + n; ++i) {
        cc.insert(uf.findset(i));
    }
    cout << min(rr.size(), cc.size()) - 1 << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}