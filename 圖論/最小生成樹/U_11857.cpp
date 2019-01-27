#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge {
    int u, v; LL w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
vector<int> pa;
int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m && (n || m)) {
        vector<Edge> edges;
        while (m--) {
            int u, v; LL w; cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end());
        int cnt = 0; LL ans = 0;
        pa.clear(); pa.resize(n);
        for (int i = 0 ; i < n ; i++)
            pa[i] = i;
        for (auto &e : edges) {
            int x = find(e.u);
            int y = find(e.v);
            if (x == y) continue;
            pa[x] = y;
            ans = max(ans, e.w);
            cnt++;
            if (cnt == n - 1)
                break;
        }
        if (cnt != n - 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
    }
}
