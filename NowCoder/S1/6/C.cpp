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
    int solve(int n, vector<int>& array) {
        sort(array.begin(), array.end());
        int left = array[0], right = array[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (left > right) {
                ans = max(ans, array[i] - right);
                right = array[i];
            }
            else {
                ans = max(ans, array[i] - left);
                left = array[i];
            }
        }
        ans = max(ans, abs(left - right));
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v0 = {2, 1, 1, 3, 2};
    cout << solution.solve(5, v0) << "\n";
    vector<int> v1 = {30, 10, 20};
    cout << solution.solve(3, v1) << "\n";
    return 0;
}