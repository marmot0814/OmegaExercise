#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T--) {
        double v0, theta, x1, h1, h2;
        cin >> v0 >> theta >> x1 >> h1 >> h2;
        double t = x1 / v0 / cos(theta * PI / 180);
        double y = v0 * t * sin(theta * PI / 180) - 0.5 * 9.81 * t * t;
        if (h1 + 1 <= y && y <= h2 - 1)
            cout << "Safe\n";
        else
            cout << "Not safe\n";
    }
}
