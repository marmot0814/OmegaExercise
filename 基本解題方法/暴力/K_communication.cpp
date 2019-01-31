#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int j = 0 ; j < n ; j++) {
        int num; cin >> num;
        for (int i = 0 ; i < 256 ; i++) {
            if (((i ^ (i << 1)) & ((1 << 8) - 1)) != num)
                continue;
            cout << i << ' ';
            break;
        }
    }
    cout << '\n';
}
