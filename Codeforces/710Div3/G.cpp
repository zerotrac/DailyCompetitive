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

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string s;

inline void work() {
    cin >> s;
    int last[26];
    memset(last, -1, sizeof(last));
    for (int i = 0; i < s.size(); ++i) {
        last[s[i] - 'a'] = i;
    }

    string ans;
    bool inside[26];
    memset(inside, false, sizeof(inside));
    for (int i = 0; i < s.size(); ++i) {
        if (inside[s[i] - 'a']) {
            continue;
        }
        while (!ans.empty() && s[i] > ans.back() && last[ans.back() - 'a'] > i) {
            inside[ans.back() - 'a'] = false;
            ans.pop_back();
        }
        inside[s[i] - 'a'] = true;
        ans.push_back(s[i]);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}