#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> vis(n, 0);
    vector<vector<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q; q.push(0);
    vis[0] = 1;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (vis[v])
                continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    bool ok = true;
    for (int i = 0 ; i < n ; i++)
        if (!vis[i])
            cout << i + 1 << '\n', ok = false;
    if (ok)
        cout << "Connected\n";
}
