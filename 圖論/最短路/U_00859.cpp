#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
struct ANS {
    int x, y, d;
    bool operator < (const ANS &rhs) const {
        return x == rhs.x ? y < rhs.y : x > rhs.x;
    }
};
const int _dx[] = {0, 0, 1};
const int _dy[] = {1, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    int n, m; while (cin >> n >> m) {
        if (first) first = false; else cout << '\n';
        vector<vector<int> > G(n, vector<int>(m, 0));
        for (int i = 0 ; i < 4 * m ; i++) {
            int x, y; cin >> x >> y; x--, y--;
            G[x][y] = 1;
        }
        pii s; cin >> s.F >> s.S; s.F--, s.S--;
        vector<vector<int> > dist(n, vector<int>(m, -1));
        dist[s.F][s.S] = 0;
        queue<pii> q; q.push(s);
        set<ANS> ans;
        while (q.size()) {
            auto p = q.front(); q.pop();
            for (int dx = 0 ; dx <= 1 ; dx++) {
                for (int dy = -1 ; dy <= 1 ; dy++) {
                    if (dx == 0 && dy == 0)
                        continue;
                    pii nt = {p.F + dx, p.S + dy};
                    if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                        continue;
                    if (!G[nt.F][nt.S])
                        continue;
                    pii tar = {p.F + dx * 2, p.S + dy * 2};
                    if (tar.F < 0 || tar.F >= n || tar.S < 0 || tar.S >= m)
                        continue;
                    if (G[tar.F][tar.S])
                        continue;
                    if (~dist[tar.F][tar.S])
                        continue;
                    dist[tar.F][tar.S] = dist[p.F][p.S] + 1;
                    ans.insert({tar.F, tar.S, dist[tar.F][tar.S]});
                    q.push(tar);
                }
            }
        }
        for (int d = 0 ; d < 3 ; d++) {
            pii nt = {s.F + _dx[d], s.S + _dy[d]};
            if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                continue;
            if (G[nt.F][nt.S])
                continue;
            ans.insert({nt.F, nt.S, 1});
        }
        for (auto &a : ans)
            cout << a.x + 1 << ' ' << a.y + 1 << ' ' << a.d << '\n';
    }
}
