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
    vector<int> icecream(int n, int m, int t, int* c, int cLen) {
        sort(c, c + m);
        int remain = m % n;
        if (!remain) {
            remain = n;
        }
        int ans = -t;
        for (int i = remain - 1; i < m; i += n) {
            ans += t;
            ans = max(ans, c[i]);
            ans += t;
        }
        return {ans, m / n + (m % n != 0)};
    }
};

int main() {
    Solution solution;
    int* v = new int[3];
    v[0] = 10;
    v[1] = 30;
    v[2] = 40;
    auto ret = solution.icecream(2, 3, 10, v, 3);
    cout << ret[0] << " " << ret[1] << "\n";
    return 0;
}