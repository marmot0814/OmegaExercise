#include <bits/stdc++.h>
using namespace std;
int encode(int i, int j) {
    return i * 2000 + j;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n + 2, vector<char>(m + 2, '0'));
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> G[i][j];
    queue<int> q; q.push(encode(0, 0));
    vector<vector<int> > vis(n + 2, vector<int>(m + 2, 0));
    vis[0][0] = 1;
    int ans = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (int d = 0 ; d < 4 ; d++) {
            int x = p / 2000 + dx[d];
            int y = p % 2000 + dy[d];
            if (x < 0 || x >= n + 2 || y < 0 || y >= m + 2)
                continue;
            if (G[x][y] == '1') {
                ans++;
            } else {
                if (vis[x][y])
                    continue;
                q.push(encode(x, y));
                vis[x][y] = 1;
            }
        }
    }
    cout << ans << '\n';
}
