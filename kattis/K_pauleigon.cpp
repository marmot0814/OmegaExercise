#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p, q; cin >> n >> p >> q;
    if ((p + q) % (2 * n) < n)
        cout << "paul\n";
    else
        cout << "opponent\n";
}
