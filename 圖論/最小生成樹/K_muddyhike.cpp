#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int encode(pii pos, int n, int m) {
    return pos.F * m + pos.S;
}
struct Edge { 
    int u, v, w; 
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
int find(int x, vector<int> &pa) { return pa[x] == x ? x : pa[x] = find(pa[x], pa); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > G(n, vector<int>(m));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    vector<Edge> edges;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (i != n - 1)
                edges.push_back({encode({i, j}, n, m), encode({i + 1, j}, n, m), max(G[i][j], G[i + 1][j])});
            if (j != m - 1) 
                edges.push_back({encode({i, j}, n, m), encode({i, j + 1}, n, m), max(G[i][j], G[i][j + 1])});
        }
    }
    for (int i = 0 ; i < n ; i++) {
        edges.push_back({n * m    , encode({i,     0}, n, m), 0});
        edges.push_back({n * m + 1, encode({i, m - 1}, n, m), 0});
    }
    sort(edges.begin(), edges.end());
    vector<int> pa; for (int i = 0 ; i < n * m + 2 ; i++) pa.push_back(i);
    int ans = 0;
    for (auto &e : edges) {
        if (find(n * m, pa) == find(n * m + 1, pa)) break;
        int x = find(e.u, pa);
        int y = find(e.v, pa);
        if (x == y) continue;
        ans = max(ans, e.w);
        pa[x] = y;
    }
    cout << ans << '\n';
}
