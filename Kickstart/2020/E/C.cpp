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

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

LL e[100010], r[100010];
int id[100010];
int n;

inline void work() {
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> e[i] >> r[i];
        sum += e[i];
    }

    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int i, int j) {
        return e[i] + r[i] > e[j] + r[j];
    });

    priority_queue<int, vector<int>, greater<int>> barrier;
    int pos = 1;
    while (pos <= n && sum < e[id[pos]] + r[id[pos]]) {
        barrier.push(id[pos]);
        ++pos;
    }
    // cout << "sum = " << sum << " " << e[id[1]] << " " << r[id[1]] << "\n";
    // cout << "size = " << barrier.size() << "\n";
    int killed = 0;
    LL best = 0;
    int bestkilled = 0;
    BIT<LL> bit(n);
    for (int i = 1; i <= n; ++i) {
        bit.update(i, e[i]);
    }
    while (!barrier.empty()) {
        ++killed;
        int rmv = barrier.top();
        barrier.pop();
        LL ans = sum + bit.query(rmv - 1);
        if (ans > best) {
            best = ans;
            bestkilled = killed - 1;
        }
        bit.update(rmv, -e[rmv]);
        sum -= e[rmv];
        while (pos <= n && sum < e[id[pos]] + r[id[pos]]) {
            barrier.push(id[pos]);
            ++pos;
        }
    }
    if (killed == n) {
        cout << bestkilled << " " << best << "\n";
    }
    else {
        cout << killed << " INDEFINITELY\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}