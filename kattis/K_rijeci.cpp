#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a = 1, b = 0;
    while (n--) {
        int new_b = b + a;
        int new_a = b;
        a = new_a;
        b = new_b;
    }
    cout << a << ' ' << b << '\n';
}
