#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n, m; cin >> n >> m;
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        vector<vector<int> > G(n);
        while (m--) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
        }
        int ans = 0, u = 0;
        while (G[u].size()) {
            ans += data[u];
            int maxV = 0, max_idx = -1;
            for (auto v : G[u]) {
                if (maxV < data[v]) {
                    maxV = data[v];
                    max_idx = v;
                }
            }
            u = max_idx;
        }
        ans += data[u];
        cout << ans << ' ' << u << '\n';
    }
}
