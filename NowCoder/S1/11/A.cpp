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
    string solve(string str) {
        string ans;
        for (char ch: str) {
            ans.push_back(ch);
            while (ans.size() > 1) {
                int l = ans.size();
                if (ans[l - 2] == '0' && ans[l - 1] == '0') {
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back('1');
                }
                else if (ans[l - 2] == '1' && ans[l - 1] == '1') {
                    ans.pop_back();
                    ans.pop_back();
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.solve("00110001") << "\n";
    return 0;
}