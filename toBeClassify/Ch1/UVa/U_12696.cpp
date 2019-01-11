#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int cnt = 0;
    int t; cin >> t; while (t--) {
        double a, b, c, w;
        cin >> a >> b >> c >> w;
        if (w > 7) {
            cout << 0 << '\n';
            continue;
        }
        if (a + b + c <= 125) {
            cout << 1 << '\n';
            cnt++;
            continue;
        }
        if (a <= 56 && b <= 45 && c <= 25) {
            cout << 1 << '\n';
            cnt++;
            continue;
        }
        cout << 0 << '\n';
    }
    cout << cnt << '\n';
}
