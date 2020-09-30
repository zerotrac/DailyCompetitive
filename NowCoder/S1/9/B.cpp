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

class Solution {
private:
    vector<int> ans, freq, pre, suf;

public:
    void dfs(int al, int ar, int bl, int br, int cl, int cr) {
        if (al > ar) {
            return;
        }
        if (al == ar) {
            ans[cl] = pre[al];
            return;
        }
        int bal = 0;
        int happy = -1;
        for (int i = 0; i < ar - al; ++i) {
            ++freq[pre[al + i + 1]];
            if (!freq[pre[al + i + 1]]) --bal; else ++bal;
            --freq[suf[bl + i]];
            if (!freq[suf[bl + i]]) --bal; else ++bal;
            if (!bal) {
                happy = i;
                break;
            }
        }
        ans[cl + happy + 1] = pre[al];
        dfs(al + 1, al + happy + 1, bl, bl + happy, cl, cl + happy);
        dfs(al + happy + 2, ar, bl + happy + 1, br - 1, cl + happy + 2, cr);
    }

    vector<int> solve(int n, vector<int>& pre_, vector<int>& suf_) {
        ans.resize(n);
        freq.resize(n + 1);
        pre = pre_;
        suf = suf_;
        dfs(0, n - 1, 0, n - 1, 0, n - 1);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> u = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v = {3, 4, 2, 6, 7, 5, 1};
    vector<int> w = solution.solve(7, u, v);
    // vector<int> u = {1};
    // vector<int> v = {1};
    // vector<int> w = solution.solve(1, u, v);
    for (int e: w) cout << e << " "; cout << "\n";
    return 0;
}