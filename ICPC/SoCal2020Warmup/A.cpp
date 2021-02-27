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

mt19937 gen{random_device{}()};
uniform_int_distribution<int> dis(1, 1000000);
static constexpr int MAXN = 100000000;
int a[MAXN];
LL sum;

inline void work() {
    for (int i = 0; i < MAXN; ++i) {
        a[i] = dis(gen);
    }
    reverse(a, a + MAXN);
    for (int i = 0; i < MAXN; ++i) {
        sum += a[i];
    }
    cout << sum << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}