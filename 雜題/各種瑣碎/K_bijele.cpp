#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tar[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0 ; i < 6 ; i++) {
        int v; cin >> v;
        cout << tar[i] - v << ' ';
    }
    cout << '\n';
}
