#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int p, a, b, c, d;
double f(int x) {
    return p * (sin(a * x + b) + cos(c * x + d) + 2);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
        int n; while (cin >> p >> a >> b >> c >> d >> n) {
        double maxV = -INF, ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            maxV = max(maxV, f(i));
            ans = max(ans, maxV - f(i));
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }

}
