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

int n, p;
int a[200010], id[200010];

inline void work() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
    }

    sort(id + 1, id + n + 1, [&](int i, int j) { 
        return a[i] < a[j];
    });

    LL ans = 0;
    int rest = n - 1;
    UF uf(n + 1);

    for (int i = 1; i <= n; ++i) {
        int idx = id[i];
        if (a[idx] > p) {
            break;
        }
        for (int j = idx - 1; j >= 1; --j) {
            if (a[j] % a[idx] != 0) {
                break;
            }
            if (uf.unite(j, idx)) {
                ans += a[idx];
                --rest;
            }
            else {
                break;
            }
        }
        for (int j = idx + 1; j <= n; ++j) {
            if (a[j] % a[idx] != 0) {
                break;
            }
            if (uf.unite(j, idx)) {
                ans += a[idx];
                --rest;
            }
            else {
                break;
            }
        }
    }

    ans += (LL)rest * p;
    cout << ans << endl;
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