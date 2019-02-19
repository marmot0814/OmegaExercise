#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int v, w;
};
const int INF = 0x3f3f3f3f;
int dfs(int u, int pa, vector<vector<Edge> > &G) {
    if ((int)G[u].size() == 1 && u != pa) return INF;
    int ret = 0;
    for (auto &e : G[u]) {
        if (e.v == pa) continue;
        ret += min(dfs(e.v, u, G), e.w);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, rt; while (cin >> n >> rt) {
        vector<vector<Edge> > G(n); rt--;
        for (int i = 0 ; i < n - 1 ; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        cout << dfs(rt, rt, G) << '\n';
    }
}
