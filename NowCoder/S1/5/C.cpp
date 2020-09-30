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

template<typename T>
class BIT_opsum {
public:
    T operator() (const T& u, const T& v) const {
        return u + v;
    }
};

template<typename T, typename Accumulate = BIT_opsum<T>>
class BIT {
private:
    vector<T> tree;
    Accumulate op;
    int n;

public:
    BIT(int _n, Accumulate _op = Accumulate{}): n(_n), tree(_n + 1), op(_op) {}

    static int lowbit(int x) {
        return x & (-x);
    }
    
    void update(int x, T value) {
        while (x <= n) {
            tree[x] = op(tree[x], value);
            x += lowbit(x);
        }
    }

    T query(int x) const {
        T ans{};
        while (x) {
            ans = op(ans, tree[x]);
            x -= lowbit(x);
        }
        return ans;
    }

    T query(int x, int y) const {
        return query(y) - query(x - 1);
    }
};

class ArrayOps {
public:
    template<typename T, class EQ_FN = equal_to<T>, class LT_FN = less<T>>
    static vector<int> discretization(const vector<T>& u, EQ_FN&& equal_fn = {}, LT_FN&& less_fn = {}) {
        int n = u.size();
        if (!n) {
            return vector<int>();
        }
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {return less_fn(u[i], u[j]);});
        vector<int> ret(n);
        ret[id[0]] = 1;
        for (int i = 1; i < n; ++i) {
            ret[id[i]] = ret[id[i - 1]] + !equal_fn(u[id[i - 1]], u[id[i]]);
        }
        return ret;
    }
};

class Solution {
public:
    long long getNumValidPairs(int n, int m, vector<int>& a) {
        priority_queue<LL, vector<LL>, greater<LL>> q;
        for (int i = 0; i < m; ++i) {
            q.push(0);
        }

        vector<LL> t;
        for (int i = 0; i < n; ++i) {
            LL best = q.top();
            q.pop();
            t.push_back(best + a[i]);
            q.push(best + a[i]);
        }

        vector<int> tt = ArrayOps::discretization(t);
        BIT<int> bit(n);
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i - bit.query(tt[i]);
            bit.update(tt[i], 1);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v0 = {5, 4, 3, 2, 1};
    cout << solution.getNumValidPairs(5, 5, v0) << "\n";
    return 0;
}