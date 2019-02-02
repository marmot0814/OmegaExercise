#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dfs(int u, int p, vector<int> &vis, int &stamp, vector<vector<int> > &G, vector<pii> &ans) {
    vis[u] = ++stamp;
    int ret = vis[u];
    for (auto &v : G[u]) {
        if (v == p) continue;
        if (vis[v]) {
            ret = min(ret, vis[v]);
        } else {
            int low = dfs(v, u, vis, stamp, G, ans);
            if (vis[u] < low) {
                ans.push_back({u, v});
            }
            ret = min(ret, low);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<vector<int> > G(n);
        for (int i = 0 ; i < n ; i++) {
            int u; cin >> u;
            string num_str; cin >> num_str;
            for (auto &c : num_str)
                if (!isdigit(c))
                    c = ' ';
            stringstream ss; ss << num_str;
            int m; ss >> m;
            while (m--) {
                int v; cin >> v;
                G[u].push_back(v);
            }
        }
        vector<int> vis(n, 0);
        int stamp = 0; vector<pii> ans;
        for (int i = 0 ; i < n ; i++) {
            if (vis[i]) continue;
            dfs(i, -1, vis, stamp, G, ans);
        }
        cout << ans.size() << " critical links\n";
        for (auto &p : ans)
            if (p.second < p.first)
                swap(p.first, p.second);
        sort(ans.begin(), ans.end());
        for (auto &p : ans)
            cout << p.first << " - " << p.second << '\n';
        cout << '\n';
    }
}
