#include <bits/stdc++.h>
using namespace std;
const int MAXP = 1e3 + 5;
vector<bool> isP(MAXP, true);
vector<int> P;
void set_prime() {
    isP[0] = isP[1] = false;
    for (int i = 2 ; i < MAXP ; i++) {
        if (isP[i]) P.push_back(i);
        for (auto &p : P) {
            if (i * p >= MAXP) break;
            isP[i * p] = false;
            if (i % p == 0) break;
        }
    }
}
int extgcd(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    int res = extgcd(b, a % b, y, x);
    return y -= a / b * x, res;
}
int modInv(int a, int m) {
    int x, y, d = extgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set_prime();
    int t; cin >> t; while (t--) {
        int n, e; cin >> n >> e;
        int p = 0, q = 0;
        for (auto &v : P) {
            if (n % v != 0)
                continue;
            p = v, q = n / v;
            break;
        }
        cout << modInv(e, (p - 1) * (q - 1)) << '\n';
    }
}
