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

int a[100010], id[100010];
int n;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
    }
    sort(a + 1, a + n + 1);
    int mid = (n + 1) / 2;
    sort(id + 1, id + n + 1, [&](int i, int j) {
        int di = abs(i - mid);
        int dj = abs(j - mid);
        return (di < dj) || (di == dj && i > j);
    });
    for (int i = 1; i <= n; ++i) {
        cout << a[id[i]] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}