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

int n, m, x;

inline vector<int> check(vector<unordered_set<int>> perm, int start) {
    vector<int> ans;
    vector<int> rest(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        rest[i] = perm[i].size();
    }
    for (int i = 0; i < n; ++i) {
        int u;
        if (i == 0) {
            u = start;
        }
        else {
            int choose = -1;
            for (int j = 0; j < n - 1; ++j) {
                if (rest[j] == 1) {
                    if (choose != -1) {
                        return {};
                    }
                    choose = j;
                }
            }
            if (choose == -1) {
                return {};
            }
            for (int j = i - 1, sz = perm[choose].size(); j >= i - sz + 1; --j) {
                if (!perm[choose].count(ans[j])) {
                    return {};
                }
                perm[choose].erase(ans[j]);
            }
            u = *perm[choose].begin();
        }
        ans.push_back(u);
        for (int j = 0; j < n - 1; ++j) {
            if (perm[j].count(u)) {
                --rest[j];
            }
        }
    }

    return ans;
}

inline void work() {
    cin >> n;
    vector<unordered_set<int>> perm(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            perm[i].insert(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> ans = check(perm, i);
        if (ans.size()) {
            for (int elem: ans) {
                cout << elem << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
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