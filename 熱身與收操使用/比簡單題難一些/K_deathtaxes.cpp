#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0; double val = 1;
    string op; while (cin >> op) {
        if (op[0] == 'b') {
            int x, y; cin >> x >> y;
            val = (cnt * val + x * y) / (cnt + x);
            cnt += x;
        } else if (op[0] == 'm') {
            int x; cin >> x;
            cnt /= x;
            val *= x;
        } else if (op[1] == 'e') {
            int x, y; cin >> x >> y;
            cnt -= x;
        } else if (op[1] == 'p') {
            int x; cin >> x;
            cnt *= x;
            val /= x;
        } else {
            int y; cin >> y;
            cout << fixed << setprecision(3) << cnt * (y - max(y - val, 0.0) * 0.3) << '\n';
        }
    }
}
