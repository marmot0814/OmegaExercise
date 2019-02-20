#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    int deg = (b + 360 - a) % 360;
    if (deg > 180)
        cout << deg - 360 << '\n';
    else
        cout << deg << '\n';
}
