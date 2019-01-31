#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool check(LL M, LL q, LL m, LL s, LL l) {
    while (m--) {
        LL cap = M;
        while (l && cap - q >= 0)
            cap -= q, l--;
        while (s && cap - 1 >= 0)
            cap -= 1, s--;
    }
    return s == 0 && l == 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL q, m, s, l; cin >> q >> m >> s >> l;
    LL L = -1, R = 2e10 + 5;
    while (R - L > 1) {
        LL M = (R + L) >> 1;
        (check(M, q, m, s, l) ? R : L) = M;
    }
    cout << R << '\n';
}
