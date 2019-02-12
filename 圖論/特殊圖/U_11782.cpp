#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void inputTree(vector<int> &w, int i) {
    if (i >= (int)w.size()) return ;
    cin >> w[i];
    inputTree(w, i * 2);
    inputTree(w, i * 2 + 1);
}
int solve(vector<int> &w, int i, int k, vector<vector<int> > &dp) {
    if (i >= (int)w.size()) return -INF;
    if (dp[i][k] != -INF) return dp[i][k];
    dp[i][k] = w[i];
    for (int j = 1 ; j < k ; j++)
        dp[i][k] = max(dp[i][k], solve(w, 2 * i, j, dp) + solve(w, 2 * i + 1, k - j, dp));
    return dp[i][k];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && ~n) {
        int k; cin >> k;
        vector<int> w(1 << (n + 1));
        vector<vector<int> > dp(1 << (n + 1), vector<int>(k + 1, -INF));
        inputTree(w, 1);
        cout << solve(w, 1, k, dp) << '\n';
    }
}
