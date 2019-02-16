#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double x; cin >> x;
    int n; cin >> n;
    double ans = 0;
    while (n--) {
        double a, b; cin >> a >> b;
        ans += a * b;
    }
    ans *= x;
    cout << fixed << setprecision(10) << ans << '\n';
}
