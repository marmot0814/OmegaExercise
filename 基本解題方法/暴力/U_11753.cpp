#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n, k; cin >> n >> k;
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        vector<int> rev = data;
        reverse(rev.begin(), rev.end());
        vector<vector<int> > dp(data.size() + 1, vector<int>(data.size() + 1, 0));
        for (int i = 1 ; i <= (int)data.size() ; i++) {
            for (int j = 1 ; j <= (int)rev.size() ; j++) {
                if (data[i - 1] == rev[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        int ans = data.size() - dp[data.size()][rev.size()];
        if (ans == 0) {
            cout << "Too easy\n";
        } else if (ans > k) {
            cout << "Too difficult\n";
        } else cout << ans << '\n';
    }
}
