#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int ans = 1;
        for (int i = 1 ; i <= n ; i++)
            ans *= i, ans %= 10;
        cout << ans << '\n';
    }
}
