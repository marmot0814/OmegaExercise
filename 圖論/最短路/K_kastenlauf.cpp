#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int dist(pii a, pii b) {
    return abs(a.F - b.F) + abs(a.S - b.S);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n; n += 2;
        vector<pii> pos(n);
        for (auto &p : pos)
            cin >> p.F >> p.S;
        vector<vector<int> > G(n);
        for (int i = 0 ; i < n ; i++)
            for (int j = i + 1 ; j < n ; j++)
                if (dist(pos[i], pos[j]) <= 1000)
                    G[i].push_back(j), G[j].push_back(i);
        vector<bool> vis(n, false);
        queue<int> q; q.push(0); vis[0] = true;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &v : G[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
        }
        if (vis[n - 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}
