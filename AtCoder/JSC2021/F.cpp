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

#include <atcoder/segtree>

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

int m, n, q;
int t[200010], x[200010], y[200010];
int a[200010], b[200010];
int rep[200010];

struct S {
    int cnt;
    LL value;

    S(): cnt(0), value(0) {}
    S(int _cnt, LL _value): cnt(_cnt), value(_value) {}

    S& upd(int dcnt, LL dvalue) {
        cnt += dcnt;
        value += dvalue;
        return *this;
    }
};

S op(S a, S b) { return {a.cnt + b.cnt, a.value + b.value}; }

S e() { return {}; }

inline void work() {
    cin >> m >> n >> q;
    vector<int> v = {0};
    for (int i = 1; i <= q; ++i) {
        cin >> t[i] >> x[i] >> y[i];
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i) {
        rep[i] = v[i];
    }

    atcoder::segtree<S, op, e> sega(v.size()), segb(v.size());
    sega.set(0, {m, 0});
    segb.set(0, {n, 0});
    LL ans = 0;

    for (int i = 1; i <= q; ++i) {
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin();
        if (t[i] == 1) {
            auto down0 = segb.prod(0, a[x[i]]);
            ans -= (LL)rep[a[x[i]]] * down0.cnt;
            ans += down0.value;

            auto down1 = segb.prod(0, y[i]);
            ans -= down1.value;
            ans += (LL)rep[y[i]] * down1.cnt;

            sega.set(a[x[i]], sega.get(a[x[i]]).upd(-1, -rep[a[x[i]]]));
            sega.set(y[i], sega.get(y[i]).upd(1, rep[y[i]]));
            a[x[i]] = y[i];
        }
        else {
            auto down0 = sega.prod(0, b[x[i]]);
            ans -= (LL)rep[b[x[i]]] * down0.cnt;
            ans += down0.value;

            auto down1 = sega.prod(0, y[i]);
            ans -= down1.value;
            ans += (LL)rep[y[i]] * down1.cnt;

            segb.set(b[x[i]], segb.get(b[x[i]]).upd(-1, -rep[b[x[i]]]));
            segb.set(y[i], segb.get(y[i]).upd(1, rep[y[i]]));
            b[x[i]] = y[i];
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}