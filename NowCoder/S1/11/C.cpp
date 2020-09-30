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
public:
    vector<int> solve(int n, int k, vector<int>& s) {
        unordered_map<int, int> freq;
        for (int num: s) {
            ++freq[num];
        }
        int l = 1, r = n, best = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cur = 0;
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                cur += it->second / mid;
            }
            if (cur >= k) {
                best = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        vector<int> ans;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int cnt = it->second / best;
            for (int i = 0; i < cnt; ++i) {
                ans.push_back(it->first);
            }
        }
        sort(ans.begin(), ans.end());
        ans.resize(k);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v1 = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    vector<int> v2 = {1, 2, 3, 2, 4, 3, 1};
    vector<int> v3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    auto p = solution.solve(12, 5, v1); for (int num: p) cout << num << " "; cout << "\n";
    auto q = solution.solve(7, 3, v2); for (int num: q) cout << num << " "; cout << "\n";
    auto r = solution.solve(10, 5, v3); for (int num: r) cout << num << " "; cout << "\n";
    return 0;
}