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

int a[2010];
int n, v;

inline void work() {
    cin >> n;
    
    // step 1: find a good magnet
    int i;
    for (i = 2; i <= n; ++i) {
        cout << "? " << 1 << " " << i - 1 << endl;
        cout << i << endl;
        for (int j = 1; j < i; ++j) {
            cout << j << " ";
        }
        cout << endl;

        cin >> v;
        if (v) {
            break;
        }
    }
    
    // step 2: check other magnets on the right
    memset(a, 0, sizeof(a));
    a[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
        cout << "? 1 1" << endl;
        cout << i << endl;
        cout << j << endl;

        cin >> v;
        if (v) {
            a[j] = 1;
        }
    }

    // step 3: binary search on the left to find the other good magnet
    int l = 1, r = i - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        // query [l, mid]
        cout << "? " << 1 << " " << mid - l + 1 << endl;
        cout << i << endl;
        for (int j = l; j <= mid; ++j) {
            cout << j << " ";
        }
        cout << endl;

        cin >> v;
        if (v) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    a[l] = 1;

    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
        if (!a[j]) {
            ++cnt;
        }
    }
    cout << "! " << cnt;
    for (int j = 1; j <= n; ++j) {
        if (!a[j]) {
            cout << " " << j;
        }
    }
    cout << endl;
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