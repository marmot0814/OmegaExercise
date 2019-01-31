#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) { return x & (-x); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n; vector<int> data(n);
        for (auto &v : data) cin >> v;
        vector<int> dp(1 << n, 0);
        for (int S = 1 ; S < (1 << n) ; S++)
            dp[S] = dp[S ^ lowbit(S)] + data[__lg(lowbit(S))];
        int sum = dp[(1 << n) - 1];
        vector<int> ans(n, 0);
        for (int i = 0 ; i < n ; i++) {
            for (int S = 0 ; S < (1 << n) ; S++) {
                if (S & (1 << i)) continue;
                if (dp[S] <= sum / 2 && dp[S | (1 << i)] > sum / 2)
                    ans[i]++;
            }
        }
        for (int i = 0 ; i < n ; i++)
            cout << "party " << i + 1 << " has power index " << ans[i] << '\n';
        if (t) cout << '\n';
    }
}
