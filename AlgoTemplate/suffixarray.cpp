#include <vector>
#include <string>
 
using namespace std;
 
class SuffixArraySimple {
public:
    vector<int> sa, rank;
    string st;
 
public:
    SuffixArraySimple(const string& st_): st{st_}, sa(st_.size()), rank(st_.size()) {
        int n = st.size();
        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {{st[i], -1}, i};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            sa[i] = v[i].second;
            rank[sa[i]] = (i ? (st[sa[i - 1]] == st[sa[i]] ? rank[sa[i - 1]] : rank[sa[i - 1]] + 1) : 0);
        }
        vector<int> newrank(n);
        for (int k = 0; (1 << k) < n; ++k) {
            for (int i = 0; i < n; ++i) {
                v[i] = {{rank[i], (i + (1 << k) < n ? rank[i + (1 << k)] : -1)}, i};
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < n; ++i) {
                sa[i] = v[i].second;
                newrank[sa[i]] = (i ? ((v[sa[i - 1]].first == v[sa[i]].first) ? newrank[sa[i - 1]] : newrank[sa[i - 1]] + 1) : 0);
            }
            rank = newrank;
        }
    }
};
