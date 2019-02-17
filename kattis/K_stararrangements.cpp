#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    cout << n << ":\n";
    for (int i = 2 ; i + i - 1 <= n ; i++) {
        if (n % (i + i - 1) == 0 || (n - i) % (i + i - 1) == 0)
            cout << i << ',' << i - 1 << '\n';
        if (2 * i <= n && n % i == 0)
            cout << i << ',' << i << '\n';
    }
}
