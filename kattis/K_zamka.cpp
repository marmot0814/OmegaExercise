#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int L, D, X; cin >> L >> D >> X;
    for (int i = L ; i <= D ; i++) {
        int x = i, cnt = 0;
        while (x)
            cnt += x % 10, x /= 10;
        if (cnt == X) {
            cout << i << '\n';
            break;
        }
    }
    for (int i = D ; i >= L ; i--) {
        int x = i, cnt = 0;
        while (x)
            cnt += x % 10, x /= 10;
        if (cnt == X) {
            cout << i << '\n';
            break;
        }
    }
}
