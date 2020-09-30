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

int a[110][110];
int n;

inline void work() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int trace = 0;
    for (int i = 0; i < n; ++i) {
        trace += a[i][i];
    }
    int rcnt = 0, ccnt = 0;
    unordered_set<int> s;
    // rows
    for (int i = 0; i < n; ++i) {
        s.clear();
        for (int j = 0; j < n; ++j) {
            if (s.count(a[i][j])) {
                ++rcnt;
                break;
            }
            s.insert(a[i][j]);
        }
    }
    // cols
    for (int j = 0; j < n; ++j) {
        s.clear();
        for (int i = 0; i < n; ++i) {
            if (s.count(a[i][j])) {
                ++ccnt;
                break;
            }
            s.insert(a[i][j]);
        }
    }
    cout << trace << " " << rcnt << " " << ccnt << "\n";
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