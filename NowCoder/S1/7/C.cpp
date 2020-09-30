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
private:
    static constexpr int mod = 1000000007;

public:
    tuple<int, int, int, int> mult(int a, int b, int c, int d, int e, int f, int g, int h) {
        int p = ((long long)a * e + (long long)b * g) % mod;
        int q = ((long long)a * f + (long long)b * h) % mod;
        int r = ((long long)c * e + (long long)d * g) % mod;
        int s = ((long long)c * f + (long long)d * h) % mod;
        return {p, q, r, s};
    }

    int calc(long long n, int b, int c) {
        int i00 = b, i01 = c, i10 = 1, i11 = 0;
        int u00 = 1, u01 = 0, u10 = 0, u11 = 1;
        while (n) {
            if (n & 1) {
                tie(u00, u01, u10, u11) = mult(u00, u01, u10, u11, i00, i01, i10, i11);
            }
            tie(i00, i01, i10, i11) = mult(i00, i01, i10, i11, i00, i01, i10, i11);
            n >>= 1;
        }
        return u00;
    }

    long long nthElement(long long n, long long b, long long c) {
        // a0 = 0, a1 = 1
        // ai = c ai-1 + b ai-2
        // n LL
        // b c int
        return calc(n - 1, (int)c, (int)b);
    }
};

int main() {
    Solution solution;
    cout << solution.nthElement(2, 1, 1) << "\n";
    cout << solution.nthElement(5, 1, 2) << "\n";
    return 0;
}