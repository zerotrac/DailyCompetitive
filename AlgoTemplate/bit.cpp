#include <vector>

using namespace std;

template<typename T>
class BIT {
private:
    vector<T> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, T value) {
        while (x <= n) {
            tree[x] += value;
            x += lowbit(x);
        }
    }

    T query(int x) const {
        T ans{};
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};