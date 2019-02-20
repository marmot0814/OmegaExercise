#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c; cin >> r >> c;
    c = r - c;
    cout << fixed << setprecision(10) << 100.0 * c * c / r / r << '\n';
}
