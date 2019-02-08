#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
typedef long long LL;
const LL MOD = 1001113;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL dp[MAXN][MAXN]; memset(dp, 0, sizeof(dp));
    for (int i = 0 ; i < MAXN ; i++)
        dp[i][0] = 1;
    for (int i = 1 ; i < MAXN ; i++)
        for (int j = 1 ; j < i ; j++)
            dp[i][j] = ((j + 1) * dp[i - 1][j] % MOD + (i - j) * dp[i - 1][j - 1] % MOD) % MOD;
    int t; cin >> t; while (t--) {
        int kase; cin >> kase; cout << kase << ' ';
        int n, v; cin >> n >> v;
        cout << dp[n][v] << '\n';
    }
}
