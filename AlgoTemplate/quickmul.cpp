#include <iostream>

using namespace std;

using LL = long long;
const int mod = 1000000007;

// 快速幂
// 有些题目中可能 y 是 LL 类型
inline int quickmul(int x, int y) {
    int ret = 1, mul = x;
    while (y) {
        if (y & 1) {
            ret = (LL)ret * mul % mod;
        }
        mul = (LL)mul * mul % mod;
        y >>= 1;
    }
    return ret;
}
