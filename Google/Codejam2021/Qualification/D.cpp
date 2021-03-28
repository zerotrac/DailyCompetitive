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

int n, q, x;
int a[100];

inline bool work() {
    cout << "1 2 3" << endl;
    cin >> x;
    if (x == 1) {
        a[1] = 2;
        a[2] = 1;
        a[3] = 3;
    }
    else if (x == 2) {
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
    }
    else {
        a[1] = 1;
        a[2] = 3;
        a[3] = 2;
    }

    for (int i = 4; i <= n; ++i) {
        int l = 0, r = i - 1;
        while (r - l > 1) {
            int cnt = r - l + 1;
            int u = cnt / 3;
            int v = cnt / 3 + (cnt % 3 == 2);
            cout << i << " " << a[l + u] << " " << a[l + u + v] << endl;
            cin >> x;
            if (x == i) {
                r = l + u + v - 1;
                l = l + u;
            }
            else if (x == a[l + u]) {
                r = l + u - 1;
            }
            else {
                l = l + u + v;
            }
        }
        if (l + 1 == r) {
            if (l == 0) {
                cout << i << " " << a[r] << " " << a[r + 1] << endl;
                cin >> x;
                if (x == i) {
                    ++l;
                }
            }
            else {
                cout << i << " " << a[l] << " " << a[r] << endl;
                cin >> x;
                if (x == a[r]) {
                    ++l;
                }
            }
        }
        for (int j = i - 1; j > l; --j) {
            a[j + 1] = a[j];
        }
        a[l + 1] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    int ind;
    cin >> ind;
    return ind == 1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T >> n >> q;
    for (int _ = 1; _ <= T; ++_) {
        if (!work()) {
            break;
        }
    }
    return 0;
}