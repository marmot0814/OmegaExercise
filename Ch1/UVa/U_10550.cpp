#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int st, a, b, c;
    while (cin >> st >> a >> b >> c && (st || a || b || c)) {
        int ans = 1080;
        ans += (st - a + 40) % 40 * 9;
        ans += ( b - a + 40) % 40 * 9;
        ans += ( b - c + 40) % 40 * 9;
        cout << ans << '\n';
    }

}
