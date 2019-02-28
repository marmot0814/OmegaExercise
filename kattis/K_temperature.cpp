#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double X, Y; cin >> X >> Y;
    if (Y == 1)
        if (X) cout << "IMPOSSIBLE\n";
        else cout << "ALL GOOD\n";
    else cout << fixed << setprecision(10) << -X / (Y - 1) << '\n';
}
