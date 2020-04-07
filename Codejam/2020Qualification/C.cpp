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

struct event {
    int ts, type, id;
    event(int _ts, int _type, int _id): ts(_ts), type(_type), id(_id) {}
    bool operator< (const event& that) const {
        return ts < that.ts || (ts == that.ts && type > that.type);
    }
};

int n, x, y;

inline void work() {
    cin >> n;
    vector<event> v;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        v.emplace_back(x, 0, i);
        v.emplace_back(y, 1, i);
    }
    sort(v.begin(), v.end());
    bool cfree = true, jfree = true;
    int cdo = 0, jdo = 0;
    string ans(n, ' ');
    for (const event& ev: v) {
        if (ev.type == 0) {
            if (cfree) {
                cfree = false;
                cdo = ev.id;
                ans[ev.id - 1] = 'C';
            }
            else if (jfree) {
                jfree = false;
                jdo = ev.id;
                ans[ev.id - 1] = 'J';
            }
            else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        else {
            if (cdo == ev.id) {
                cfree = true;
            }
            else {
                jfree = true;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}