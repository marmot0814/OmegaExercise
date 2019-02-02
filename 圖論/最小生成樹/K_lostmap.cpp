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
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        pa.clear(); for (int i = 0 ; i < n ; i++) pa.push_back(i);
        vector<Edge> edges;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                LL w; cin >> w;
                if (i >= j) continue;
                edges.push_back({i, j, w});
            }
        }
        sort(edges.begin(), edges.end());
        int cnt = 0;
        vector<Edge> ans;
        for (auto &e : edges) {
            if (cnt == n - 1) break;
            int x = find(e.u);
            int y = find(e.v);
            if (x == y) continue;
            pa[x] = y;
            ans.push_back(e);
        }
        for (auto &e : ans)
            cout << e.u + 1 << ' ' << e.v + 1 << '\n';
    }
}
