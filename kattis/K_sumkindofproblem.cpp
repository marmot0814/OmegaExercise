#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        long long n; cin >> n;
        cout << (1 + n) * n / 2 << ' ' << (1 + 2 * n - 1) * n / 2 << ' ' << (2 + 2 * n) * n / 2 << '\n';
    }
}
