#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b;
    int ans = 0;
    while (sum >= c) {
        int add = sum / c;
        ans += add;
        sum -= sum / c * c;
        sum += add;
    }
    cout << ans << '\n';
}
