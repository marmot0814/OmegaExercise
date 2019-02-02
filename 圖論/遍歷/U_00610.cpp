#include <bits/stdc++.h>
using namespace std;
int stamp;
vector<vector<int> > G;
vector<int> vis;
int dfs(int u, int p) {
    vis[u] = ++stamp;
    int ret = vis[u];
    for (auto &v : G[u]) {
        if (v == p) continue;
        if (vis[v]) {
            if (vis[v] <= vis[u])
                cout << u + 1 << ' ' << v + 1 << '\n';
            ret = min(ret, vis[v]);
        } else {
            int low = dfs(v, u);
            cout << u + 1 << ' ' << v + 1 << '\n';
            if (low > vis[u]) 
                cout << v + 1 << ' ' << u + 1 << '\n';
            ret = min(ret, low);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, kase = 0; while (cin >> n >> m && (n || m)) {
        cout << ++kase << "\n\n";
        G.clear(); G.resize(n);
        while (m--) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        stamp = 0;
        vis.clear(); vis.resize(n, 0);
        for (int i = 0 ; i < n ; i++) {
            if (vis[i]) continue;
            dfs(i, -1);
        }
        cout << "#\n";
    }
}
