#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    char G[MAXN][MAXN];
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            cin >> G[i][j];
    queue<pair<pii, int> > q;
    int vis[MAXN][MAXN]; memset(vis, -1, sizeof(vis));
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            if (G[i][j] == '*')
                q.push({{i, j}, 0}), vis[i][j] = 0;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            if (G[i][j] == 'S')
                q.push({{i, j}, 1}), vis[i][j] = 0;
    int ans = -1;
    while (q.size()) {
        auto p = q.front(); q.pop();
        pii pos = p.first;
        if (G[pos.first][pos.second] == 'D' && p.second == 1) {
            ans = vis[pos.first][pos.second];
            break;
        }
        for (int d = 0 ; d < 4 ; d++) {
            pii nt = {pos.first + dx[d], pos.second + dy[d]};
            if (nt.first >= n || nt.first < 0 || nt.second >= m || nt.second < 0)
                continue;
            if (~vis[nt.first][nt.second])
                continue;
            if (p.second == 0 && G[nt.first][nt.second] != '.')
                continue;
            if (p.second == 1 && G[nt.first][nt.second] == 'X')
                continue;
            vis[nt.first][nt.second] = vis[pos.first][pos.second] + 1;
            q.push({nt, p.second});
        }
    }
    if (~ans)
        cout << ans << '\n';
    else
        cout << "KAKTUS\n";
}
