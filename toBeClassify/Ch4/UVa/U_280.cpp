#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<vector<int> > G(n);
        int u; while (cin >> u && u) { u--;
            int v; while (cin >> v && v) { v--;
                G[u].push_back(v);
            }
        }
        int q; cin >> q; while (q--) {
            vector<bool> d(n, false);
            int cnt = 0, s; cin >> s; s--;
            queue<int> q; q.push(s);
            while (q.size()) {
                int p = q.front(); q.pop();
                for (auto &v : G[p]) {
                    if (d[v]) continue;
                    d[v] = true;
                    q.push(v);
                    cnt++;
                }
            }
            cout << n - cnt;
            for (int i = 0 ; i < n ; i++)
                if (!d[i])
                    cout << ' ' << i + 1;
            cout << '\n';
        }
    }
}
