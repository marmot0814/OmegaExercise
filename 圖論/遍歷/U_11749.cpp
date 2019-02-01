#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Edge {
    int v; LL w;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m && (n || m)) {
        LL maxW = -INF;
        vector<vector<Edge> > G(n);
        while (m--) {
            int u, v; LL w; cin >> u >> v >> w;
            u--, v--;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
            maxW = max(maxW, w);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            queue<int> q; q.push(i);
            int cnt = 0;
            while (q.size()) {
                int p = q.front(); q.pop();
                cnt++;
                for (auto &e : G[p]) {
                    if (vis[e.v]) continue;
                    if (e.w != maxW) continue;
                    vis[e.v] = true;
                    q.push(e.v);
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}
