#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; while (cin >> a >> b && a && b) {
        cout << a / b << ' ' << a - a / b * b << " / " << b << '\n';
    }
}
