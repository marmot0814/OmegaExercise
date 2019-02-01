#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > G(n);
    vector<pair<int, int> > Edges;
    for (int i = 0 ; i < n - 1 ; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        Edges.push_back({u, v});
    }
    vector<int> color(n, 0);
    for (int i = 0 ; i < n ; i++) {
        if (color[i]) continue;
        queue<int> q; q.push(i);
        color[i] = 1;
        while (q.size()) {
            int p = q.front(); q.pop();
            for (auto &v : G[p]) {
                if (color[v]) continue;
                color[v] = color[p] * -1;
                q.push(v);
            }
        }
    }
    for (auto &e : Edges) {
        if (color[e.second] == 1)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
    
}
