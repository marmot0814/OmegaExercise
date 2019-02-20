#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    double M = 0, S = 0, m, s;
    while (n--) {
        cin >> m >> s;
        M += m * 60, S += s;
    }
    if (S <= M) cout << "measurement error\n";
    else cout << fixed << setprecision(10) << S / M << '\n';
}
