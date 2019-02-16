#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int MOD = 24 * 60;
    int h, m; cin >> h >> m;
    int cur = h * 60 + m;
    cur -= 45;
    cur = (cur + MOD) % MOD;
    cout << cur / 60 << ' ' << cur % 60 << '\n';
}
