#include <bits/stdc++.h>
using namespace std;
const int MAXW = 25000 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int tar; cin >> tar; tar /= 10;
        int n; cin >> n;
        bool dp[MAXW]; memset(dp, false, sizeof(dp));
        dp[0] = true; int sum = 0;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v; v /= 10;
            sum += v;
            for (int j = MAXW - 1 ; j >= v ; j--)
                dp[j] |= dp[j - v];
        }
        if (sum < tar) cout << "NO SOLUTION\n";
        else { 
            while (!dp[tar]) tar++;
            cout << tar * 10 << '\n';
        }
    }
}
