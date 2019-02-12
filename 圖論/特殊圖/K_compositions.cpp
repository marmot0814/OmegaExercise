#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int n, vector<int> &data) {
    if (~dp[n]) return dp[n];
    if (n == 0) return dp[n] = 1;
    dp[n] = 0;
    for (auto &v : data) {
        if (v > n) break;
        dp[n] += solve(n - v, data);
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int n, m, k; cin >> n >> m >> k;
        vector<int> data;
        dp.clear(); dp.resize(n + 1, -1);
        for (int i = 1 ; i <= n ; i++) {
            if (i % k == m) continue;
            data.push_back(i);
        }
        cout << solve(n, data) << '\n';
    }
}
