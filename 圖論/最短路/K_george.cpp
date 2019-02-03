#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge { int v, w; };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int s, t, k, g; cin >> s >> t >> k >> g; s--, t--;
    vector<int> list(g);
    for (auto &v : list) cin >> v, v--;
    vector<vector<Edge> > G(n);
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<vector<int> > L(n, vector<int>(n, -1));
    vector<vector<int> > R(n, vector<int>(n, -1));
    int sum = 0;
    for (int i = 0 ; i < (int)list.size() - 1 ; i++) {
        int w = 0;
        for (auto &e : G[list[i]]) {
            if (e.v != list[i + 1])
                continue;
            w = e.w;
            break;
        }
        L[list[i]][list[i + 1]] = L[list[i + 1]][list[i]] = sum;
        R[list[i]][list[i + 1]] = R[list[i + 1]][list[i]] = sum + w - 1;
        sum += w;
    }
    vector<int> dist(n, INF);
    queue<int> q; q.push(s); dist[s] = k;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto &e : G[u]) {
            int d = dist[u] + e.w;
            if (L[u][e.v] <= dist[u] && dist[u] <= R[u][e.v])
                d += R[u][e.v] - dist[u] + 1;
            if (dist[e.v] <= d)
                continue;
            dist[e.v] = d;
            q.push(e.v);
        }
    }
    cout << dist[t] - k << '\n';
}
