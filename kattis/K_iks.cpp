#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int fpow(int a, int n) {
    if (n == 0) return 1;
    int k = fpow(a, n >> 1);
    int ret = k * k;
    if (n % 2) ret *= a;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    linear_prime();
    int n; cin >> n;
    map<int, int> total;
    vector<map<int, int> > data(n);
    for (auto &m : data) {
        int v; cin >> v;
        for (int i = 0 ; v != 1 ; i++)
            while (v % P[i] == 0) 
                m[P[i]]++, total[P[i]]++, v /= P[i];
    }
    int ans = 1, minV = 0;
    for (auto &p : total) {
        ans *= fpow(p.first, p.second / n);
        for (auto &m : data) {
            if (m.count(p.first))
                minV += max(0, p.second / n - m[p.first]);
            else minV += p.second / n;
        }
    }
    cout << ans << ' ' << minV << '\n';
}
