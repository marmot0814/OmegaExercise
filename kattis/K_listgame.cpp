#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<bool> isP(MAXN, true);
vector<int> P;
void linear_prime() {
    isP[0] = isP[1] = false;
    for (int i = 2 ; i < MAXN ; i++) {
        if (isP[i]) P.push_back(i);
        for (auto p : P) {
            if (i * p >= MAXN) break;
            isP[i * p] = false;
            if (i % p == 0) break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    linear_prime();
    int n; cin >> n;
    int ans = 0;
    for (auto &p : P) {
        if (n % p)
            continue;
        while (n % p == 0)
            n /= p, ans++;
        if (n < p)
            break;
    }
    if (n != 1) ans++;
    cout << ans << '\n';
}
