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

int w[1010], s[1010], v[1010];
int id[1010];
LL f[20010];
int n;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> s[i] >> v[i];
    }
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [](int u, int v) {return w[u] + s[u] < w[v] + s[v];});
    for (int i = 1; i <= n; ++i) {
        for (int j = w[id[i]] + s[id[i]]; j >= w[id[i]]; --j) {
            f[j] = max(f[j], f[j - w[id[i]]] + v[id[i]]);
        }
    }
    cout << *max_element(f, f + w[id[n]] + s[id[n]] + 1) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}