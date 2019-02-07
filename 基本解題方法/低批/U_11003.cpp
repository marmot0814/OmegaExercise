#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXW = 1e4 + 5;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<pii> data(n);
        for (auto &p : data)
            cin >> p.F >> p.S;
        reverse(data.begin(), data.end());
        int dp[MAXW]; memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        int ans = 0;
        for (auto &p : data)
            for (int i = p.S + p.F ; i >= p.F ; i--)
                dp[i] = max(dp[i], dp[i - p.F] + 1),
                ans = max(ans, dp[i]);
        cout << ans << '\n';

    }
}
