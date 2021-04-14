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
int a[1000010], b[1000010], c[1000010];

LL dfs(int l1, int r1, int l2, int r2) {
    int mid = (l2 + r2) / 2;
    int trans = -1;
    LL best = 0;
    for (int i = l1; i <= r1; ++i) {
        if (c[mid] <= b[i]) {
            continue;
        }
        LL area = (LL)(c[mid] - b[i]) * (a[c[mid]] + a[b[i]]);
        if (area >= best) {
            best = area;
            trans = i;
        }
    }
    if (l2 <= mid - 1 && trans != -1) {
        best = max(best, dfs(l1, trans, l2, mid - 1));
    }
    if (mid + 1 <= r2) {
        if (trans != -1) {
            best = max(best, dfs(trans, r1, mid + 1, r2));
        }
        else {
            best = max(best, dfs(l1, r1, mid + 1, r2));
        }
    }
    return best;
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (!p || -a[i] < - a[b[p]]) {
            b[++p] = i;
        }
    }
    int q = 0;
    for (int i = 1; i <= n; ++i) {
        while (q && a[c[q]] <= a[i]) {
            --q;
        }
        c[++q] = i;
    }
    cout << dfs(1, p, 1, q) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}