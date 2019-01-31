#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3fLL;
LL getPrice(LL x) {
    LL res = 0;
    if (x <= 100) return res + x * 2;
    res += 100 * 2;
    if (x <= 10000) return res + (x - 100) * 3;
    res += (10000 - 100) * 3;
    if (x <= 1000000) return res + (x - 10000) * 5;
    res += (1000000 - 10000) * 5;
    return res + (x - 1000000) * 7;
}
LL getEnergy(LL x) {
    LL L = 0, R = INF;
    while (R - L > 1) {
        LL M = (R + L) >> 1;
        (getPrice(M) < x ? L : R) = M;
    }
    return R;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL A, B; while (cin >> A >> B) {
        if (A == 0 && B == 0) break;
        LL totalE = getEnergy(A);
        LL L = 0, R = totalE;
        while (R - L > 1) {
            LL M = (R + L) >> 1;
            (getPrice(totalE - M) - getPrice(M) > B ? L : R) = M;
        }
        cout << getPrice(R) << '\n';
    }
}
