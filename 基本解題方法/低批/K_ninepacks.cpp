#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXW = 1e5 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int dp[2][MAXW]; memset(dp, INF, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    int n; cin >> n; for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        for (int j = MAXW - 1 ; j >= v ; j--)
            dp[0][j] = min(dp[0][j], dp[0][j - v] + 1);
    }
    int m; cin >> m; for (int i = 0 ; i < m ; i++) {
        int v; cin >> v;
        for (int j = MAXW - 1 ; j >= v ; j--)
            dp[1][j] = min(dp[1][j], dp[1][j - v] + 1);
    }
    int ans = INF;
    for (int i = 1 ; i < MAXW ; i++)
        ans = min(ans, dp[0][i] + dp[1][i]);
    if (ans == INF) cout << "impossible\n";
    else cout << ans << '\n';
}
