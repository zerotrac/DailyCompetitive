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

unordered_map<int, vector<int>> ans;
int a[3010];
string st;
int n, k;

inline void work() {
    cin >> n >> k;
    cin >> st;
    for (int i = 1; i <= n; ++i) {
        a[i] = (st[i - 1] == 'L' ? 0 : 1);
    }
    int left = 0, right = 0;
    for (;; ++left) {
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 1 && a[i + 1] == 0) {
                flag = true;
                ans[left + 1].push_back(i);
                swap(a[i], a[i + 1]);
                ++right;
                ++i;
            }
        }
        if (!flag) {
            break;
        }
    }
    if (left <= k && k <= right) {
        bool finished = false;
        for (int i = 1; i <= left && !finished; ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                if (k == left - i + 1) {
                    cout << ans[i].size() - j;
                    for (int l = j; l < ans[i].size(); ++l) {
                        cout << " " << ans[i][l];
                    }
                    cout << "\n";
                    for (int i0 = i + 1; i0 <= left; ++i0) {
                        cout << ans[i0].size();
                        for (int num: ans[i0]) {
                            cout << " " << num;
                        }
                        cout << "\n";
                    }
                    finished = true;
                    break;
                }
                else {
                    cout << "1 " << ans[i][j] << "\n";
                    --k;
                }
            }
        }
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}