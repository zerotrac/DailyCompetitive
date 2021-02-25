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
long double k;
long double h[100010], s[100010], d[100010];

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    int coef = n;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + k * coef;
        d[i] = h[i] - s[i];
        coef -= 2;
    }

    auto cross = [](long double x1, long double y1, long double x2, long double y2) {
        return x1 * y2 - x2 * y1;
    };

    vector<int> v = {0, 1};
    for (int i = 2; i <= n + 1; ++i) {
        while (v.size() > 1) {
            long double x1 = v[v.size() - 1] - v[v.size() - 2];
            long double y1 = d[v[v.size() - 1]] - d[v[v.size() - 2]];
            long double x2 = i - v[v.size() - 1];
            long double y2 = d[i] - d[v[v.size() - 1]];
            if (cross(x1, y1, x2, y2) > -1e-7) {
                v.pop_back();
            }
            else {
                break;
            }
        }
        v.push_back(i);
    }

    int ptr = 0;
    long double best = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[ptr + 1] == i) {
            ++ptr;
        }
        else {
            d[i] = (d[v[ptr]] * (v[ptr + 1] - i) + d[v[ptr + 1]] * (i - v[ptr])) / (v[ptr + 1] - v[ptr]);
            h[i] = d[i] + s[i];
        }
        best = max(best, h[i]);
    }

    cout << fixed << setprecision(10) << best << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}