// reference:
// scc: https://oi-wiki.org/graph/scc/
// bcc cutting vertex: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
// bcc cutting edge: https://www.geeksforgeeks.org/bridge-in-a-graph/

#include <vector>

using namespace std;

using PII = pair<int, int>;

class TarjanSCC {
private:
    // low, dfn, group are basic concepts of SCC/BCC
    static vector<int> low, dfn, group;
    // stack, if-in-stack are concepts of SCC
    static vector<int> stk, instk;
    // father is a concept of BCC
    static vector<int> fa;
    // timestamp
    static int ts;
    // SCC count
    static int scnt;

private:
    static void getSCC_(const vector<vector<int>>& edges, int u) {
        low[u] = dfn[u] = ++ts;
        stk.push_back(u);
        instk[u] = 1;
        for (int v: edges[u]) {
            if (dfn[v] == -1) {
                getSCC_(edges, v);
                low[u] = min(low[u], low[v]);
            }
            else if (instk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            // new SCC
            while (true) {
                int w = stk.back();
                group[w] = scnt;
                instk[w] = 0;
                stk.pop_back();
                if (w == u) {
                    break;
                }
            }
            ++scnt;
        }
    }

    static void getCuttingVertex_(const vector<vector<int>>& edges, int u, int parent, vector<int>& ans) {
        low[u] = dfn[u] = ++ts;
        fa[u] = parent;
        int child = 0;
        bool isCV = false;
        for (int v: edges[u]) {
            if (dfn[v] == -1) {
                ++child;
                getCuttingVertex_(edges, v, u, ans);
                low[u] = min(low[u], low[v]);
                if (!isCV && parent != -1 && low[v] >= dfn[u]) {
                    ans.push_back(u);
                    isCV = true;
                }
            }
            else if (v != fa[u]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (!isCV && parent == -1 && child >= 2) {
            ans.push_back(u);
        }
    }

    static void getCuttingEdge_(const vector<vector<int>>& edges, int u, int parent, vector<PII>& ans) {
        low[u] = dfn[u] = ++ts;
        fa[u] = parent;
        for (int v: edges[u]) {
            if (dfn[v] == -1) {
                getCuttingEdge_(edges, v, u, ans);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.emplace_back(u, v);
                }
            }
            else if (v != fa[u]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    // input: node count, graph
    // output: SCC count, SCC status
    static pair<int, vector<int>> getSCC(int n, const vector<vector<int>>& edges) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        group.assign(n, -1);
        stk.clear();
        instk.assign(n, 0);
        ts = -1;
        scnt = 0;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getSCC_(edges, i);
            }
        }
        return {scnt, group};
    }

    // input: node count, graph
    // output: cutting vertices
    static vector<int> getCuttingVertex(int n, const vector<vector<int>>& edges) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        fa.assign(n, -1);
        ts = -1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingVertex_(edges, i, -1, ans);
            }
        }
        return ans;
    }

    // input: node count, graph
    // output: cutting edges
    static vector<PII> getCuttingEdge(int n, const vector<vector<int>>& edges) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        fa.assign(n, -1);
        ts = -1;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdge_(edges, i, -1, ans);
            }
        }
        return ans;
    }
};

vector<int> TarjanSCC::low, TarjanSCC::dfn, TarjanSCC::group;
vector<int> TarjanSCC::stk, TarjanSCC::instk;
vector<int> TarjanSCC::fa;
int TarjanSCC::ts;
int TarjanSCC::scnt;