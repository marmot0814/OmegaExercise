#include <bits/stdc++.h>
using namespace std;
void trans(int &x, int m) {
    while (x < 0) x += m;
    x %= m;
}
const int MAXW = 2e6 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        int sum = 0;
        vector<int> data(n);
        for (auto &v : data) {
            cin >> v; trans(v, m);
            sum += v; v *= 2;
        }
        bool dp[MAXW];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (auto &v : data) {
            if (v == 0) continue;
            for (int j = sum * 2 ; j >= v ; j--)
                dp[j] |= dp[j - v];
        }
        sum %= m;
        bool legal = false;
        for (int i = sum ; i < MAXW ; i += m) {
            if (dp[i]) {
                legal = true;
                break;
            }
        }
        if (legal)
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }
}
