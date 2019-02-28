#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        int ans_x = -1, ans_y = -1, ans = 0;
        for (int x = 1 ;; x++) {
            if (l1 * x >= lt || a1 * x >= at)
                break;
            if ((lt - l1 * x) % l2 || (at - a1 * x) % a2)
                continue;
            int y1 = (lt - l1 * x) / l2;
            int y2 = (at - a1 * x) / a2;
            if (y1 != y2)
                continue;
            ans_x = x, ans_y = y1, ans++;
            if (ans > 1)
                break;
        }
        if (ans == 1) {
            cout << ans_x << ' ' << ans_y << '\n';
        } else
            cout << "?\n";
    }
}
/*
l1 * x + l2 * y = lt
a1 * x + a2 * y = at
*/
