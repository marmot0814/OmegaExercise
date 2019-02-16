#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q, w, h; cin >> q >> w >> h;
    int sum = w * w + h * h;
    while (q--) {
        int n; cin >> n;
        n *= n;
        if (n > sum)
            cout << "NE\n";
        else
            cout << "DA\n";
    }
}
