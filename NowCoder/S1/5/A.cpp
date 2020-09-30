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
    string decode(string str, int d) {
        string s;
        for (char c = '0'; c <= '9'; ++c) {
            s += c;
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            s += c;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            s += c;
        }
        string ans;
        for (char c: str) {
            int pos = s.find(c) - d;
            if (pos < 0) {
                pos += s.size();
            }
            ans += s[pos];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.decode("pqyeqfgt", 2) << "\n";
    cout << solution.decode("123ABCabc", 3) << "\n";
    return 0;
}