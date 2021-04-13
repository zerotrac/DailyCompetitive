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

// https://codeforces.com/blog/entry/85881?#comment-736905

int n, x, y;
unordered_map<int, int> rep;
int indeg[300010], pos[300010];
int found[300010];

inline void clear() {
    rep.clear();
    for (int i = 1; i <= n; ++i) {
        indeg[i] = 0;
    }
}

inline void work() {
    cin >> n;
    clear();

    vector<pair<int, int>> store;

    int idx = n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            if (!rep.count(y)) {
                rep[y] = ++idx;
                indeg[rep[y]] = 0;
            }
            y = rep[y];
            store.emplace_back(i, y);
            ++indeg[i];
            ++indeg[y];
        }
    }

    auto cmp = [&](int i, int j) {
        return (indeg[i] > indeg[j]) || (indeg[i] == indeg[j] && i < j);
    };

    // g is undirected
    // g2 is directed
    vector<vector<int>> g(idx + 1), g2(idx + 1);
    for (const auto& [u, v]: store) {
        g[u].push_back(v);
        g[v].push_back(u);
        if (cmp(u, v)) {
            g2[u].push_back(v);
        }
        else {
            g2[v].push_back(u);
        }
    }

    for (int i = 1; i <= idx; ++i) {
        pos[i] = i;
    }
    sort(pos + 1, pos + idx + 1, cmp);

    for (int idxp = 1; idxp <= idx; ++idxp) {
        int p = pos[idxp];
        for (int q: g2[p]) {
            for (int r: g[q]) {
                if (cmp(p, r)) {
                    found[r] = 0;
                }
            }
        }
        for (int q: g2[p]) {
            for (int r: g[q]) {
                if (cmp(p, r)) {
                    if (found[r]) {
                        // p-q-r-found[r]-p
                        if (p > n) {
                            cout << q << " " << found[r] << "\n";
                            return;
                        }
                        else {
                            cout << p << " " << r << "\n";
                            return;
                        }
                    }
                    found[r] = q;
                }
            }
        }
    }

    cout << "-1\n";
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