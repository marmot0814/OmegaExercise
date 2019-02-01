#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> data(n); for (auto &v : data) cin >> v;
    vector<vector<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> vis(n, false);
    bool legal = true;
    for (int i = 0 ; i < n ; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        queue<int> q; q.push(i);
        int sum = 0;
        while (q.size()) {
            int p = q.front(); q.pop();
            sum += data[p];
            for (auto &v : G[p]) {
                if (vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
        }
        if (sum != 0) legal = false;
        if (!legal) break;
    }
    if (legal) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";

}
