#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t; while (t--) {
        int r, e, c; cin >> r >> e >> c;
        if (r + c > e) {
            cout << "do not advertise\n";
        } else if (r + c < e) {
            cout << "advertise\n";
        } else {
            cout << "does not matter\n";
        }
    }
}
