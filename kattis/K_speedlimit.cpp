#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; while (cin >> n && ~n) {
        int cnt = 0, ans = 0;
        while (n--) {
            int x, y; cin >> x >> y;
            ans += x * (y - cnt);
            cnt = y;
        }
        cout << ans << " miles\n";
    }
}
