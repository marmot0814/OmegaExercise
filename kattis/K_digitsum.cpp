#include <bits/stdc++.h>
using namespace std;
long long digit_sum(long long x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
long long solve(long long x) {
    if (x == 0) return 0;
    if (x % 10) return solve(x - 1) + digit_sum(x - 1);
    return 10 * solve(x / 10) + 45 * (x / 10);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        long long l, r; cin >> l >> r;
        cout << solve(r + 1) - solve(l) << '\n';
    }
}
