#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int b, n; cin >> b >> n;
        int ans = 0;
        while (n) {
            int tar = n % b;
            ans += tar * tar;
            n /= b;
        }
        cout << ans << '\n';
    }
}
