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

string s, t;

inline void work() {
    getline(cin, s);
    getline(cin, t);
    int m = s.size(), n = t.size();
    unordered_set<char> ans;
    for (int i = 0, j = 0; i < m;) {
        int iu = i;
        while (iu + 1 < m && s[iu + 1] == s[i]) {
            ++iu;
        }
        int ju = j;
        while (ju + 1 < n && t[ju + 1] == t[j]) {
            ++ju;
        }
        if ((iu - i + 1) * 2 == (ju - j + 1)) {
            ans.insert(s[iu]);
        }
        i = iu + 1;
        j = ju + 1;
    }
    for (char ch: ans) {
        cout << ch;
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}