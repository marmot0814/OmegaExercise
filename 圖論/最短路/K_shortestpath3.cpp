#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge { int v; LL w; };
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, Q, s; while (cin >> n >> m >> Q >> s && n) {
        vector<vector<Edge> > G(n);
        while (m--) {
            int u, v; LL w; cin >> u >> v >> w;
            G[u].push_back({v, w});
        }
        vector<LL> d(n, INF); d[s] = 0;
        for (int i = 0 ; i < n - 1 ; i++)
            for (int u = 0 ; u < n ; u++)
                if (d[u] < INF)
                    for (auto &e : G[u])
                        d[e.v] = min(d[e.v], d[u] + e.w);
        vector<bool> n_cyc(n, false);
        bool ch = true;
        while (ch) {
            ch = false;
            for (int u = 0 ; u < n ; u++)
                if (d[u] < INF)
                    for (auto &e : G[u])
                        if (d[u] + e.w < d[e.v] && !n_cyc[e.v])
                            n_cyc[e.v] = ch = true, d[e.v] = -INF;
        }
        while (Q--) {
            int u; cin >> u;
            if (n_cyc[u])
                cout << "-Infinity\n";
            else if (d[u] == INF)
                cout << "Impossible\n";
            else
                cout << d[u] << '\n';
        }
        cout << '\n';

    }
}
