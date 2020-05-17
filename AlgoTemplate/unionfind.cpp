#include <vector>
#include <numeric>

using namespace std;

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    
    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }
    
    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }
    
    void findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
        }
    }
};
