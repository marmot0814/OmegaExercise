#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        double b, p; cin >> b >> p;
        double x = 60 / p;
        double xb = x * b;
        cout << fixed << setprecision(6) << xb - x << ' ' << xb << ' ' << xb + x << '\n';
    }
}
