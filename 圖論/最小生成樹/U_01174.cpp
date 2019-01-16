#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) { return pa[x] < 0 ? x : pa[x] = find(pa[x]); }
map<string, int> ID;
int getID(string s) {
    int sz = ID.size();
    if (!ID.count(s))
        ID[s] = sz;
    return ID[s];
}
typedef long long LL;
struct Edge {
    int u, v; LL w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
int main() {
    int t; cin >> t; while (t--) {
        ID.clear();
        int n, m; cin >> n >> m;
        vector<Edge> edges;
        while (m--) {
            string u, v; LL w;
            cin >> u >> v >> w;
            edges.push_back({getID(u), getID(v), w});
        }
        sort(edges.begin(), edges.end());
        pa.clear(); pa.resize(n, -1);
        int cnt = 0; LL sum = 0;
        for (auto &e : edges) {
            int x = find(e.u);
            int y = find(e.v);
            if (x == y) continue;
            cnt++;
            if (pa[x] < pa[y]) swap(x, y);
            pa[y] += pa[x]; pa[x] = y;
            sum += e.w;
            if (cnt == n - 1) break;
        }
        cout << sum << '\n';
        if (t) cout << '\n';
    }
}
