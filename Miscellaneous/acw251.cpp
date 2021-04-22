// acw 251 & Luogu P1494
// Mo's algorithm

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

int n, q;
int c[50010], l[50010], r[50010], id[50010];
int cnt[50010], resu[50010], resd[50010];
int ans = 0, curl, curr;

inline void init() {
    curl = l[id[1]];
    curr = r[id[1]];
    for (int i = curl; i <= curr; ++i) {
        ans += cnt[c[i]];
        ++cnt[c[i]];
    }
}

inline void work() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> l[i] >> r[i];
        id[i] = i;
    }

    int blk = sqrt(n + 1) + 1;
    sort(id + 1, id + q + 1, [&](int i, int j) {
        int bi = l[i] / blk;
        int bj = l[j] / blk;
        if (bi != bj) {
            return bi < bj;
        }
        return r[i] < r[j];
    });

    for (int i = 1; i <= q; ++i) {
        int ll = l[id[i]];
        int rr = r[id[i]];
        if (i == 1) {
            init();
        }
        else {
            while (curl - 1 >= ll) {
                --curl;
                ans += cnt[c[curl]];
                ++cnt[c[curl]];
            }
            while (curr + 1 <= rr) {
                ++curr;
                ans += cnt[c[curr]];
                ++cnt[c[curr]];
            }
            while (curl < ll) {
                ans -= cnt[c[curl]] - 1;
                --cnt[c[curl]];
                ++curl;
            }
            while (curr > rr) {
                ans -= cnt[c[curr]] - 1;
                --cnt[c[curr]];
                --curr;
            }
        }

        if (ll == rr) {
            resu[id[i]] = 0;
            resd[id[i]] = 1;
        }
        else {
            int ansu = ans;
            int ansd = (LL)(rr - ll + 1) * (rr - ll) / 2;
            int g = gcd(ansu, ansd);
            resu[id[i]] = ansu / g;
            resd[id[i]] = ansd / g;
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << resu[i] << "/" << resd[i] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}