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

struct Point {
    int x;
    int y;
    Point(int _x, int _y): x(_x), y(_y) {}
};

class Solution {
private:
    vector<vector<int>> banned;
    vector<int> freq;
    int ans;

public:
    void dfs(int pos, int lb, int n) {
        ++ans;
        for (int i = lb; i <= n; ++i) {
            if (!freq[i]) {
                for (int num: banned[i]) {
                    ++freq[num];
                }
                dfs(pos + 1, i + 1, n);
                for (int num: banned[i]) {
                    --freq[num];
                }
            }
        }
    }

    int solve(int n, int m, vector<Point>& limit) {
        banned.resize(n);
        freq.resize(n);
        ans = 0;
        for (const auto& pt: limit) {
            if (pt.x > pt.y) {
                banned[pt.y - 1].push_back(pt.x - 1);
            }
            else {
                banned[pt.x - 1].push_back(pt.y - 1);
            }
        }
        dfs(0, 0, n - 1);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<Point> v;
    v.emplace_back(1, 2);
    v.emplace_back(2, 3);
    cout << solution.solve(3, 2, v) << "\n";
    return 0;
}