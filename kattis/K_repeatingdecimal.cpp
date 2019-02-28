#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; while (cin >> a >> b >> c) {
        cout << "0.";
        while (c--) {
            a *= 10;
            cout << a / b;
            a %= b;
        }
        cout << '\n';
    }
}
