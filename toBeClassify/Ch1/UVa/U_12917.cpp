#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; while (cin >> a >> b >> c) {
        if (a + b > c) cout << "Hunters win!\n";
        else cout << "Props win!\n";
    }
}
