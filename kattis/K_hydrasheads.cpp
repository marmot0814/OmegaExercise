#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; while (cin >> a >> b && a && b) {
        int cnt = (4 - (2 * a + b) % 4) % 4;
        cout << cnt + (b + cnt) / 2 + (a + (b + cnt) / 2) / 2 << '\n';
    }
}
