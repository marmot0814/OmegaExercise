#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    char B[MAXN][MAXN];
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            cin >> B[i][j];
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (B[i][j] == '.') continue;
            ans++;
            queue<pii> q; q.push({i, j}); B[i][j] = '.';
            while (q.size()) {
                pii p = q.front(); q.pop();
                for (int dx = -1 ; dx <= 1 ; dx++) {
                    for (int dy = -1 ; dy <= 1 ; dy++) {
                        if (dx == 0 && dy == 0)
                            continue;
                        pii nt = {p.first + dx, p.second + dy};
                        if (nt.first >= n || nt.first < 0 || nt.second >= m || nt.second < 0)
                            continue;
                        if (B[nt.first][nt.second] == '.')
                            continue;
                        B[nt.first][nt.second] = '.';
                        q.push(nt);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
