#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXK = 1e2 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<int> data(n);
        for (auto &v : data) {
            cin >> v;
            v = abs(v) % m; 
        }
        bool dp[MAXN][MAXK]; memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (dp[i][j]) {
                    dp[i + 1][(j + data[i] + m) % m] = true;
                    dp[i + 1][(j - data[i] + m) % m] = true;
                }
            }
        }
        if (dp[n][0]) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}
