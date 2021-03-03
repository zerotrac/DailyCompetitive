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
int a[200010];
bool used[200010];
vector<vector<int>> cyc;
int opx[200010], opy[200010];
int op_cnt = 0;

inline void build_cyc(int u) {
    vector<int> c = {u};
    int v = a[u];
    while (v != u) {
        c.push_back(v);
        used[v] = true;
        v = a[v];
    }
    cyc.push_back(move(c));
}

inline void execute(int i, int j) {
    ++op_cnt;
    opx[op_cnt] = i;
    opy[op_cnt] = j;
    swap(a[i], a[j]);
    a[i] = -a[i];
    a[j] = -a[j];
}

inline void merge(const vector<int>& p, const vector<int>& q) {
    execute(p[0], q[0]);
    while (a[-a[p[0]]] > 0) {
        execute(p[0], -a[p[0]]);
    }
    while (a[-a[q[0]]] > 0) {
        execute(q[0], -a[q[0]]);
    }
    execute(p[0], -a[p[0]]);
}

inline void self_restore(const vector<int>& p) {
    execute(p[0], p[1]);
    execute(p[1], p[2]);
    while (a[-a[p[0]]] > 0) {
        execute(p[0], -a[p[0]]);
    }
    while (a[-a[p[1]]] > 0) {
        execute(p[1], -a[p[1]]);
    }
    execute(p[0], -a[p[0]]);
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i] && i != a[i]) {
            build_cyc(i);
        }
    }

    for (int i = 0; i < cyc.size(); i += 2) {
        if (i + 1 < cyc.size()) {
            merge(cyc[i], cyc[i + 1]);
        }
        else if (cyc[i].size() < n) {
            memset(used, false, sizeof(used));
            for (int o: cyc[i]) {
                used[o] = true;
            }
            int candidate = 0;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    candidate = j;
                    break;
                }
            }
            merge({candidate}, cyc[i]);
        }
        else {
            self_restore(cyc[i]);
        }
    }

    cout << op_cnt << "\n";
    for (int i = 1; i <= op_cnt; ++i) {
        cout << opx[i] << " " << opy[i] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}