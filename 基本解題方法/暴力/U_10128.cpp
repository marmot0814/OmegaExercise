#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int main() {
    long long dp[MAXN][MAXN][MAXN];
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;
    for (int i = 2 ; i < 15 ; i++) {
        for (int p = 1 ; p < 15 ; p++) {
            for (int r = 1 ; r < 15 ; r++) {
                dp[i][p][r] = (i - 2) * dp[i - 1][p][r] + dp[i - 1][p - 1][r] + dp[i - 1][p][r - 1];
            }
        }
    }
    int t; cin >> t; while (t--) {
        int n, p, r; cin >> n >> p >> r;
        cout << dp[n][p][r] << '\n';
    }
}
