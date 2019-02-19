#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l, m; cin >> l >> m;
    int L, M; cin >> L >> M;
    int a, b; cin >> a >> b;
    bool poss = false;
    int pos = 0;
    int x = abs(pos - l) + abs(l - L); pos = L;
    int y = abs(pos - m) + abs(m - M) + x;
    cout << x << ' ' << a << ' ' << y << ' ' << b << '\n';
    if (x <= a && y <= b)
        poss = true;
    pos = 0;
    x = abs(pos - m) + abs(m - M); pos = M;
    y = abs(pos - l) + abs(l - L) + x;
    cout << x << ' ' << a << ' ' << y << ' ' << b << '\n';
    if (x <= a && y <= b)
        poss = true;
    if (poss)
        cout << "possible\n";
    else
        cout << "impossible\n";

}
