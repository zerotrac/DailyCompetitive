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
    int solve(int n, int m, vector<int>& a) {
        int ans = 0;
        int l = 0, used = 0;
        for (int r = 0; r < n; ++r) {
            used += 1 - a[r];
            while (used > m) {
                used -= 1 - a[l];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v = {1, 0, 0, 1, 1, 1};
    cout << solution.solve(6, 1, v) << "\n";
    cout << solution.solve(6, 2, v) << "\n";
    return 0;
}