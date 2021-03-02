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

int a[100010];
int n, q, x, op;

inline void work() {
    cin >> n >> q;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ++cnt0;
        }
        else {
            ++cnt1;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cin >> op >> x;
        if (op == 1) {
            if (a[x] == 0) {
                ++cnt1;
                --cnt0;
            }
            else {
                ++cnt0;
                --cnt1;
            }
            a[x] = 1 - a[x];
        }
        else {
            cout << (x <= cnt1 ? 1 : 0) << "\n";
        }
    }    
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}