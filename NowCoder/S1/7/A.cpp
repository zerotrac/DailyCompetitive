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
};

class Solution {
private:
    vector<vector<int>> edges;
    int ans = 0;

public:
    void dfs(const vector<int>& f, int u, int parent, int cnt) {
        cnt += f[u];
        if (cnt > 2) {
            return;
        }
        bool leaf = true;
        for (int v: edges[u]) {
            if (v != parent) {
                dfs(f, v, u, cnt);
                leaf = false;
            }
        }
        if (leaf) {
            ++ans;
        }
    }

    int solve(int n, vector<Point>& Edge, vector<int>& f) {
        edges.resize(n);
        for (const Point& pt: Edge) {
            edges[pt.x - 1].push_back(pt.y - 1);
            edges[pt.y - 1].push_back(pt.x - 1);
        }
        dfs(f, 0, -1, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    
    return 0;
}