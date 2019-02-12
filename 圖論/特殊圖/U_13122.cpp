#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const double INF = 1e10  + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        vector<pii> data(n);
        for (auto &p : data)
            cin >> p.F >> p.S;
        vector<vector<double> > dp(n, vector<double>(n - m + 1, INF));
        dp[0][1] = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 2 ; j <= n - m ; j++)
                for (int k = 0 ; k < i ; k++)
                    dp[i][j] = min(dp[k][j - 1] + hypot(data[i].F - data[k].F, data[i].S - data[k].S), dp[i][j]);
        }
        cout << fixed << setprecision(3) << (int)(dp[n - 1][n - m] * 1000 + .5) / 1000. << '\n';
    }
}
