#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int cur = 0, ans = 0;
        for (auto &c : s) {
            cur *= 10;
            cur += c - '0';
            ans = max(ans, __builtin_popcount(cur));
        }
        cout << ans << '\n';
    }
}
