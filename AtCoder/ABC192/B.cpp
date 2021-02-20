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

string st;

inline void work() {
    cin >> st;
    for (int i = 0; i < st.size(); ++i) {
        char ch = st[i];
        if (i % 2 == 0 && !('a' <= ch && ch <= 'z')) {
            cout << "No\n";
            return;
        }
        if (i % 2 == 1 && !('A' <= ch && ch <= 'Z')) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}