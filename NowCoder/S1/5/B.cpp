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
    bool solve(int x) {
        for (int i = 0; i < 1000; ++i) {
            if (i * i % 1000 == x) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.solve(24) << "\n";
    return 0;
}