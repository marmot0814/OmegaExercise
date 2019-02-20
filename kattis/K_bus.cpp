#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int k; cin >> k;
        long long ans = 0;
        while (k--)
            ans = 2 * ans + 1;
        cout << ans << '\n';
    }
}
