#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int a, b, c; cin >> a >> b >> c;
        if (a > 20 || b > 20 || c > 20)
            cout << "bad\n";
        else
            cout << "good\n";
    }
}
