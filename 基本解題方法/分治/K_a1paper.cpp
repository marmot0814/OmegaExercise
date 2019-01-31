#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9;
vector<int> _data;
double solve(int n, int need) {
    if (n == (int)_data.size()) return -INF;
    if (need <= _data[n]) return 0;
    return solve(n + 1, 2 * (need - _data[n])) + (need - _data[n]) * pow(2, -(n * 2 + 1) / 4.0);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    _data.clear(); _data.resize(n + 1);
    for (int i = 2 ; i <= n ; i++)
        cin >> _data[i];
    double ans = solve(1, 1);
    if (ans < 0)
        cout << "impossible\n";
    else
        cout << fixed << setprecision(10) << ans << '\n';
}
