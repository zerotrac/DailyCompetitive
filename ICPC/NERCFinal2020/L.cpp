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

static constexpr int MAXD = 17;
int fa[200010][MAXD + 1], dep[200010];
int n, q, l, r, v;
map<int, int> pos;

inline int lift(int x, int d) {
    for (int i = MAXD; i >= 0; --i) {
        if (d >= (1 << i)) {
            x = fa[x][i];
            d -= (1 << i);
        }
    }
    return x;
}

inline int lca(int x, int y) {
    int dx = dep[x], dy = dep[y];
    if (dx < dy) {
        swap(x, y);
        swap(dx, dy);
    }
    x = lift(x, dx - dy);
    if (x == y) {
        return x;
    }
    for (int i = MAXD; i >= 0; --i) {
        int px = fa[x][i];
        int py = fa[y][i];
        if (px != py) {
            tie(x, y) = {px, py};
        }
    }
    return fa[x][0];
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> l >> r >> v;
        if (l) {
            fa[l][0] = i;
            dep[l] = dep[i] + 1;
        }
        if (r) {
            fa[r][0] = i;
            dep[r] = dep[i] + 1;
        }
        pos[v] = i;
    }

    for (int j = 1; j <= MAXD; ++j) {
        for (int i = 1; i <= n; ++i) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        if (l > pos.rbegin()->first || r < pos.begin()->first) {
            cout << "1\n";
            continue;
        }
        
        l = max(l, pos.begin()->first);
        r = min(r, pos.rbegin()->first);

        auto itl = pos.lower_bound(l);
        if (itl != pos.begin() && dep[prev(itl)->second] < dep[itl->second]) {
            itl = prev(itl);
        }
        auto itr = pos.upper_bound(r);
        if (itr == pos.end() || dep[prev(itr)->second] < dep[itr->second]) {
            itr = prev(itr);
        }

        int x = itl->second;
        int y = itr->second;
        int z = lca(x, y);

        if (l == pos.begin()->first && r == pos.rbegin()->first) {
            cout << "1\n";
        }
        else if (l == pos.begin()->first) {
            cout << (dep[y] + 1) * 2 + 1 << "\n";
        }
        else if (r == pos.rbegin()->first) {
            cout << (dep[x] + 1) * 2 + 1 << "\n";
        }
        else {
            cout << (dep[x] + dep[y] - dep[z] + 1) * 2 + 1 << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}