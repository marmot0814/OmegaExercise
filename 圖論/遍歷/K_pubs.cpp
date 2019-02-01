#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> color(n, 0);
    int minV = INF;
    for (int i = 0 ; i < n ; i++) {
        if (color[i]) continue;
        color[i] = 1;
        int cnt = 0;
        queue<int> q; q.push(i);
        while (q.size()) {
            cnt++;
            int p = q.front(); q.pop();
            for (auto &v : G[p]) {
                if (!color[v]) {
                    color[v] = color[p] * -1;
                    q.push(v);
                }
            }
        }
        minV = min(minV, cnt);
    }
    if (minV == 1) {
        cout << "Impossible\n";
    } else for (int i = 0 ; i < n ; i++) {
        if (color[i] == 1)
            cout << "pub ";
        else cout << "house ";
    }
}
