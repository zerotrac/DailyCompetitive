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

unordered_map<int, vector<PII>> lefts, rights;
LL tree[810000], tag[810000];
int n, m, x, y, z;

void pushdown(int x) {
    tree[x * 2] += tag[x];
    tag[x * 2] += tag[x];
    tree[x * 2 + 1] += tag[x];
    tag[x * 2 + 1] += tag[x];
    tag[x] = 0;
}

void pushup(int x) {
    tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
}

void update(int x, int l, int r, int ul, int ur, LL delta) {
    if (l > ur || r < ul) {
        return;
    }
    if (ul <= l && r <= ur) {
        tree[x] += delta;
        tag[x] += delta;
        return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    update(x * 2, l, mid, ul, ur, delta);
    update(x * 2 + 1, mid + 1, r, ul, ur, delta);
    pushup(x);
}

LL query(int x, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return LONG_MIN;
    }
    if (ql <= l && r <= qr) {
        return tree[x];
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    return max(query(x * 2, l, mid, ql, qr), query(x * 2 + 1, mid + 1, r, ql, qr));
}

inline void work() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        lefts[x].emplace_back(y, z);
        rights[y].emplace_back(x, z);
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (lefts.count(i)) {
            // for (auto& [_, z]: lefts[i]) {
            for (auto& _: lefts[i]) {   // atcoder c++14 only
                int z = _.second;
                update(1, 1, n + 1, 1, i, z);
            }
        }
        LL cur = query(1, 1, n + 1, 1, i);
        ans = max(ans, cur);
        update(1, 1, n + 1, i + 1, i + 1, cur);
        if (rights.count(i)) {
            // for (auto& [x, z]: rights[i]) {
            for (auto& _: rights[i]) {
                int x = _.first, z = _.second;
                update(1, 1, n + 1, 1, x, -z);
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