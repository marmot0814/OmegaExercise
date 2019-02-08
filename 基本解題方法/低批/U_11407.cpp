#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int dp[MAXN]; memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1 ; i <= 100 ; i++) {
        int v = i * i;
        for (int j = v ; j < MAXN ; j++)
            dp[j] = min(dp[j], dp[j - v] + 1);
    }
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}
