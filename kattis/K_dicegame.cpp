#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a = 0;
    for (int i = 0 ; i < 4 ; i++) {
        int v; cin >> v;
        a += v;
    }
    int b = 0;
    for (int i = 0 ; i < 4 ; i++) {
        int v; cin >> v;
        b += v;
    }
    if (a < b)
        cout << "Emma\n";
    else if (a > b)
        cout << "Gunnar\n";
    else
        cout << "Tie\n";
}
