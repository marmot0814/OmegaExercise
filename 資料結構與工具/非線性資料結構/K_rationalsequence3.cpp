#include <bits/stdc++.h>
using namespace std;
int p, q;
void solve(int n) {
    if (n == 1)
        p = 1, q = 1;
    else {
        solve(n >> 1);
        if (n % 2)
            p += q;
        else
            q += p;
    }
}
int main() {
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int n; cin >> n;
        solve(n);
        cout << p << '/' << q << '\n';
    }
}
