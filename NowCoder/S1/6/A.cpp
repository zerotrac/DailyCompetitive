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
    long long rotateRight(string str, int k) {
        long long ans = 0;
        int n = str.size();
        for (int i = n - k; i < n; ++i) {
            ans = ans * 2 + (str[i] - '0');
        }
        for (int i = 0; i < n - k; ++i) {
            ans = ans * 2 + (str[i] - '0');
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.rotateRight("10110", 2);
    return 0;
}