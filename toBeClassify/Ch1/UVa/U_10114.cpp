#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m, n; double a, b;
    while (cin >> m >> a >> b >> n) {
        if (m <= 0) break;
        queue<pair<int, double> > q;
        for (int i = 0 ; i < n ; i++) {
            int x; double y;
            cin >> x >> y;
            q.push({x, y});
        }
        int ans; double cur_q = 0, value = a + b, res = b;
        for (ans = 0 ; ; ans++) {
            if (q.size() && q.front().first == ans) {
                cur_q = q.front().second;
                q.pop();
            }
            value *= (1 - cur_q);
            if (value > res)
                break;
            res -= b / m;
        }
        cout << ans << (ans == 1 ? " month" : " months") << '\n';
    }
}
