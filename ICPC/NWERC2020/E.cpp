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
int ax, ay, bx, by;
int mx[100010], my[100010];

static constexpr int TRIAL = 100;

mt19937 gen{random_device{}()};

struct cmp {
    size_t operator() (const pair<int, int>& o) const {
        auto&& [x, y] = o;
        return hash<LL>()((LL)x * 123456 + y);
    }
};

inline bool reach(int sx, int sy, int ex, int ey) {
    // from (sx, sy) to (ex, ey)
    if (sx == ex && sy == ey) {
        return true;
    }

    unordered_set<pair<int, int>, cmp> s;
    for (int i = 1; i <= n; ++i) {
        int xx = sx + mx[i];
        int yy = sy + my[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
            s.emplace(xx, yy);
        }
    }
    if (s.count({ex, ey})) {
        return true;
    }
    for (int i = 1; i <= n; ++i) {
        int xx = ex - mx[i];
        int yy = ey - my[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
            if (s.count({xx, yy})) {
                return true;
            }
        }
    }
    return false;
}

inline void work() {
    cin >> n;
    cin >> ax >> ay >> bx >> by;
    for (int i = 1; i <= n; ++i) {
        cin >> mx[i] >> my[i];
    }

    if (reach(ax, ay, bx, by)) {
        cout << "Alice wins\n";
    }
    else {
        uniform_int_distribution<int> dis(1, n);
        for (int _ = 1; _ <= TRIAL; ++_) {
            int xx = dis(gen), yy = dis(gen);
            if (!reach(bx, by, xx, yy)) {
                cout << "tie " << xx << " " << yy << endl;
                return;
            }
        }
        cout << "Bob wins\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}