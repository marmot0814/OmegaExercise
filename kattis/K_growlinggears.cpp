#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n; double maxV = 0; int ans = -1;
        for (int i = 0 ; i < n ; i++) {
            double a, b, c; cin >> a >> b >> c;
            double x = max(0.0, b / 2 / a);
            if (maxV < -a * x * x + b * x + c)
                maxV = -a * x * x + b * x + c, ans = i + 1;
        }
        cout << ans << '\n';
    }
}
