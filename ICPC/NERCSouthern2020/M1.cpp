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

int n, x, y;
unordered_map<int, int> contains[200010];
vector<int> v[100010];
unordered_map<int, int> rep;
unordered_map<int, int> occ;
bool ss[200010];
int acnt = 0;

// static constexpr int bound = 300;

inline void work() {
    cin >> n;
    int m = 0;
    
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        v[i].reserve(x);
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            ++occ[y];
            v[i].push_back(y);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int pt = 0;
        for (int o: v[i]) {
            if (occ[o] == 1) {
                continue;
            }
            if (!rep.count(o)) {
                rep[o] = ++acnt;
            }
            v[i][pt++] = rep[o];
        }
        v[i].resize(pt);
        sort(v[i].begin(), v[i].end());
        m += pt;
    }

    int bound = sqrt(m) / 5 + 1;

    for (int i = 1; i <= n; ++i) {
        if (v[i].size() >= bound) {
            for (const auto& o: v[i]) {
                ss[o] = true;
            }
            bool found = false;
            for (int j = 1; j <= n && !found; ++j) {
                if (i == j) {
                    continue;
                } 
                int pos = 0;
                while (pos < v[j].size() && v[j][pos] < v[i][0]) {
                    ++pos;
                }
                int cnt = 0;
                while (pos < v[j].size() && v[j][pos] <= v[i].back()) {
                    if (ss[v[j][pos]]) {
                        ++cnt;
                        if (cnt == 2) {
                            cout << i << " " << j << "\n";
                            found = true;
                            break;
                        }
                    }
                    ++pos;
                }
            }
            for (const auto& o: v[i]) {
                ss[o] = false;
            }
            if (found) {
                return;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (v[i].size() < bound) {
            for (int j1 = 0; j1 < v[i].size(); ++j1) {
                auto&& mp = contains[v[i][j1]];
                for (int j2 = j1 + 1; j2 < v[i].size(); ++j2) {
                    if (mp.count(v[i][j2])) {
                        cout << i << " " << mp[v[i][j2]] << "\n";
                        return;
                    }
                    mp[v[i][j2]] = i;
                }
            }
        }
    }

    cout << "-1\n";
}

inline void prepare() {
    work();
    for (int i = 1; i <= n; ++i) {
        v[i].clear();
        v[i].shrink_to_fit();
    }
    for (int i = 1; i <= acnt; ++i) {
        contains[i].clear();
    }
    rep.clear();
    occ.clear();
    acnt = 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        prepare();
    }
    return 0;
}