#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXW = 1e4 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL dp[MAXW]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (LL i = 1 ; i <= 21 ; i++) {
        LL v = i * i * i;
        for (int j = v ; j < MAXW ; j++)
            dp[j] += dp[j - v];
    }
    int q; while (cin >> q) {
        cout << dp[q] << '\n';
    }
}
