#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 25;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int BFS(vector<vector<char> > &G, pii s, char tar) {
    G[s.first][s.second] = '.';
    queue<pii> q; q.push(s);
    int cnt = 0;
    while (q.size()) {
        pii p = q.front(); q.pop(); cnt++;
        for (int d = 0 ; d < 4 ; d++) {
            pii nt = {p.first + dx[d], p.second + dy[d]};
            nt.second += G[0].size(); nt.second %= G[0].size();
            if (nt.first >= (int)G.size() || nt.first < 0)
                continue;
            if (G[nt.first][nt.second] != tar)
                continue;
            G[nt.first][nt.second] = '.';
            q.push(nt);
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        vector<vector<char> > G(n, vector<char>(m));
        for (auto &vv : G) for (auto &v : vv) cin >> v;
        pii s; cin >> s.first >> s.second;
        char tar = G[s.first][s.second];
        BFS(G, s, tar);
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (G[i][j] != tar)
                    continue;
                ans = max(ans, BFS(G, {i, j}, tar));
            }
        }
        cout << ans << '\n';
    }
}
