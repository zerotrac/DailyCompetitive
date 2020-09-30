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

int a[100010];
int N, K;

inline void work() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int l = 1, r = 1000000000, ans = -1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        int ex = 0;
        for (int i = 0; i < N - 1; ++i) {
            ex += (a[i + 1] - a[i] - 1) / mid;
        }
        if (ex <= K) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("C.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}