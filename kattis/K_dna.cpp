#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, string &s, vector<vector<int> > &dp) {
    if (~dp[i][j]) return dp[i][j];
    if (s[j - 1] == i + 'A')
        return dp[i][j] = solve(i, j - 1, s, dp);
    return dp[i][j] = min(solve(i, j - 1, s, dp), solve(i ^ 1, j - 1, s, dp)) + 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int> > dp(2, vector<int>(s.size() + 1, -1));
    dp[0][0] = dp[1][0] = 0;
    cout << solve(0, s.size(), s, dp) << '\n';
}
