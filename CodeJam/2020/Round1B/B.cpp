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

const int LB = -1000000000;
const int RB = +1000000000;

mt19937 gen{random_device{}()};
uniform_int_distribution<int> dis(LB, RB);

PII getPoint() {
    return {dis(gen), dis(gen)};
}

char checkPoint(const PII& o) {
    if (o.first >= LB && o.first <= RB && o.second >= LB && o.second <= RB) {
        cout << o.first << " " << o.second << endl;
        string s;
        cin >> s;
        return s[0];
    }
    else {
        return 'M';
    }
} 

inline void work() {
    // Phase 1
    PII inner_point;
    while (true) {
        inner_point = getPoint();
        char fb = checkPoint(inner_point);
        if (fb == 'C') {
            return;
        }
        if (fb == 'H') {
            break;
        }
    }
    // Phase 2
    int ymin = inner_point.second, ymax = inner_point.second;
    for (int i = 30; i >= 0; --i) {
        char fb = checkPoint({inner_point.first, ymin - (1 << i)});
        if (fb == 'C') {
            return;
        }
        if (fb == 'H') {
            ymin -= (1 << i);
        }
    }
    for (int i = 30; i >= 0; --i) {
        char fb = checkPoint({inner_point.first, ymax + (1 << i)});
        if (fb == 'C') {
            return;
        }
        if (fb == 'H') {
            ymax += (1 << i);
        }
    }
    int ansy = (ymin + ymax) / 2;
    // Phase 3
    int xmin = inner_point.first, xmax = inner_point.first;
    for (int i = 30; i >= 0; --i) {
        char fb = checkPoint({xmin - (1 << i), ansy});
        if (fb == 'C') {
            return;
        }
        if (fb == 'H') {
            xmin -= (1 << i);
        }
    }
    for (int i = 30; i >= 0; --i) {
        char fb = checkPoint({xmax + (1 << i), ansy});
        if (fb == 'C') {
            return;
        }
        if (fb == 'H') {
            xmax += (1 << i);
        }
    }
    int ansx = (xmin + xmax) / 2;
    cout << ansx << " " << ansy << endl;
    string dummy;
    cin >> dummy;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T, A, B;
    cin >> T >> A >> B;
    for (int _ = 1; _ <= T; ++_) {
        work();
    }
    return 0;
}