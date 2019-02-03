#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int v, w; bool isSh;
};
bool solve(int u, vector<int> &d, vector<bool> &isOK, vector<vector<Edge> > &G) {
    if (isOK[u]) return true;
    bool ok = false;
    for (auto &e : G[u]) {
        if (d[u] + e.w != d[e.v])
            continue;
        e.isSh = solve(e.v, d, isOK, G);
        ok |= e.isSh;
    }
    return isOK[u] = ok;
}
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s, t; while (cin >> n >> m && (n || m)) {
        cin >> s >> t;
        vector<vector<Edge> > G(n);
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            G[u].push_back({v, w, false});
        }
        vector<int> d(n, INF);
        d[s] = 0;
        queue<int> q; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &e : G[u]) {
                if (d[e.v] <= d[u] + e.w)
                    continue;
                d[e.v] = d[u] + e.w;
                q.push(e.v);
            }
        }
        vector<bool> isOK(n, false);
        isOK[t] = true;
        solve(s, d, isOK, G);
        d.clear(); d.resize(n, INF);
        d[s] = 0; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &e : G[u]) {
                if (e.isSh) continue;
                if (d[e.v] <= d[u] + e.w)
                    continue;
                d[e.v] = d[u] + e.w;
                q.push(e.v);
            }
        }
        if (d[t] != INF)
            cout << d[t] << '\n';
        else
            cout << -1 << '\n';
    }
}
