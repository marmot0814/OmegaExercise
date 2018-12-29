#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        while (n > 9) {
            int _n = 0;
            while (n) {
                _n += n % 10;
                n /= 10;
            }
            n = _n;
        }
        cout << n << '\n';
    }
}
