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

int n, k;

inline void work() {
    cin >> n >> k;
    while (k) {
        if (n % k == 0) {
            for (int i = 1; i <= k; ++i) {
                cout << n / k << " ";
            }
            break;
        }
        else if (k == 3) {
            // n!=3x
            if (n % 2 == 1) {
                cout << "1 " << n / 2 << " " << n / 2 << " ";
            }
            else if (n % 4 == 0) {
                cout << n / 2 << " " << n / 4 << " " << n / 4 << " ";
            }
            else {
                cout << "2 " << (n - 2) / 2 << " " << (n - 2) / 2 << " ";
            }
            break;
        }
        else {
            cout << "1 ";
            --n;
        }
        --k;
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