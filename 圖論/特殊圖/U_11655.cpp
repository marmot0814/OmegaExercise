#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n, m; cin >> n >> m;
        vector<vector<int> > G(n);
        vector<int> ind(n, 0);
        while (m--) {
            int u, v; cin >> u >> v;
            u--, v--; ind[v]++;
            G[u].push_back(v);
        }
        vector<int> cnt(n, 0), dis(n, 0);
        queue<int> q; q.push(0); cnt[0] = 1;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &v : G[u]) {
                cnt[v] += cnt[u];
                cnt[v] %= MOD;
                dis[v] += dis[u] + cnt[u];
                dis[v] %= MOD;
                if (--ind[v]) continue;
                q.push(v);
            }
        }
        cout << dis[n - 1] << ' ' << cnt[n - 1] << '\n';
    }
}
