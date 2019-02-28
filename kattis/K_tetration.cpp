#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double n; cin >> n;
    cout << fixed << setprecision(10) << pow(n, 1 / n) << '\n';
}
