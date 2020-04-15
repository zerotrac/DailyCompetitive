#include <vector>
#include <numeric>

using namespace std;

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