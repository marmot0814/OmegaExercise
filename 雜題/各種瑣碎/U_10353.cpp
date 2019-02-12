#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        double r; cin >> r;
        cout << fixed << setprecision(12) << r / sqrt(3.0) + (1.0 + sin(114 / 180. * PI) / sin(30 / 180. * PI)) * r * sin(54 / 180. * PI) / sin(72 / 180. * PI) << ' ';
    }
}
