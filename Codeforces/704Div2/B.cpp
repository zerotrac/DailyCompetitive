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
int a[100010], b[100010];
bool used[100010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        used[i] = false;
    }

    int r = n;
    int k = 1;
    for (int i = n; i >= 1; --i) {
        if (!used[i]) {
            int l = r;
            while (a[l] != i) {
                --l;
            }
            for (int j = l; j <= r; ++j) {
                b[k++] = a[j];
                used[a[j]] = true;
            }
            r = l - 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}