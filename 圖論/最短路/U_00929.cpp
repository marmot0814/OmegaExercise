#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int> > G(n, vector<int>(m));
        for (auto &vv : G)
            for (auto &v : vv)
                cin >> v;
        vector<vector<int> > dist(n, vector<int>(m, INF));
        vector<vector<bool> > inq(n, vector<bool>(m, false));
        dist[0][0] = G[0][0];
        deque<pii> q; q.push_back({0, 0});
        inq[0][0] = true;
        while (q.size()) {
            pii p;
            if (dist[q.back().F][q.back().S] < dist[q.front().F][q.front().S])
                p = q.back(), q.pop_back();
            else
                p = q.front(), q.pop_front();
            inq[p.F][p.S] = false;
            for (int d = 0 ; d < 4 ; d++) {
                pii nt = {p.F + dx[d], p.S + dy[d]};
                if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                    continue;
                if (dist[p.F][p.S] + G[nt.F][nt.S] < dist[nt.F][nt.S]) {
                    dist[nt.F][nt.S] = dist[p.F][p.S] + G[nt.F][nt.S];
                    if (!inq[nt.F][nt.S])
                        q.push_back(nt), inq[nt.F][nt.S] = true;
                }
            }
        }
        cout << dist[n - 1][m - 1] << '\n';
    }
}
