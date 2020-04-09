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

int f[200010], g[200010];
int n, k, c;
string s;

inline void work() {
    cin >> n >> k >> c;
    cin >> s;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1];
        g[i] = -1;
        if (s[i - 1] == 'o') {
            f[i] = max(f[i], (i - c - 1 >= 0 ? f[i - c - 1] : 0) + 1);
        }
        if (f[i] == k + 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        unordered_map<int, vector<int>> v;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'o') {
                v[f[i]].push_back(i);
            }
        }
        vector<int> ans;
        int pos = v[k].back();
        if (v[k].size() == 1) {
            ans.push_back(pos);
        }
        for (int i = n - 1; i >= 1; --i) {
            for (int j = v[i].size() - 1; j >= 0; --j) {
                if (v[i][j] + c < pos) {
                    if (j == 0) {
                        ans.push_back(v[i][0]);
                    }
                    pos = v[i][j];
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for (int elem: ans) {
            cout << elem << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}