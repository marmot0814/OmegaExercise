#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
int dist(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
vector<int> pa;
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int n; while (cin >> n && n) {
        cout << "Scenario #" << ++kase << '\n';
        cout << "Frog Distance = ";
        vector<pii> data(n);
        for (auto &p : data) cin >> p.first >> p.second;
        vector<Edge> edges;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++)
                edges.push_back({i, j, dist(data[i], data[j])});
        }
        sort(edges.begin(), edges.end());
        pa.clear(); for (int i = 0 ; i < n ; i++) pa.push_back(i);
        int ans = 0;
        for (auto &e : edges) {
            if (find(0) == find(1)) break;
            int x = find(e.u);
            int y = find(e.v);
            if (x == y) continue;
            pa[x] = y;
            ans = max(ans, e.w);
        }
        cout << fixed << setprecision(3) << sqrt(ans) << '\n';
        cout << '\n';
    }

}
