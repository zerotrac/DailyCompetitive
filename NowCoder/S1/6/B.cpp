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
    int solve(int n, vector<int>& a) {
        unordered_map<int, int> need;
        for (int x: a) {
            int cnt = 0;
            while (x % 2 == 0) {
                ++cnt;
                x /= 2;
            }
            need[x] = max(need[x], cnt);
        }
        int ans = 0;
        for (auto it = need.begin(); it != need.end(); ++it) {
            ans += it->second;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v = {2, 2, 3};
    cout << solution.solve(3, v) << "\n";
    vector<int> w = {1, 3, 7};
    cout << solution.solve(3, w) << "\n";
    vector<int> q = {2, 2, 3, 4, 4, 16};
    cout << solution.solve(6, q) << "\n";
    return 0;
}