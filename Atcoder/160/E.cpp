#include <iostream>
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

vector<PII> v;
int x, y, z, a, b, c;

inline void work() {
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; ++i) {
        cin >> z;
        v.emplace_back(z, 1);
    }
    for (int i = 0; i < b; ++i) {
        cin >> z;
        v.emplace_back(z, 2);
    }
    for (int i = 0; i < c; ++i) {
        cin >> z;
        v.emplace_back(z, 3);
    }
    sort(v.begin(), v.end(), greater<PII>());
    int geta = 0, getb = 0, getc = 0;
    LL ans = 0;
    for (int i = 0; geta + getb + getc < x + y; ++i) {
        if (v[i].second == 1) {
            if (geta < x) {
                ++geta;
                ans += v[i].first;
            }
        }
        else if (v[i].second == 2) {
            if (getb < y) {
                ++getb;
                ans += v[i].first;
            }
        }
        else {
            ++getc;
            ans += v[i].first;
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