#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int ans = n / 400;
        if (n % 400) ans++;
        cout << ans << '\n';
    }
}
