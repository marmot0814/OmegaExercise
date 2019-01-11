#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    cout << "Dr. Chaz ";
    if (n < m) {
        cout << "will have ";
        cout << m - n;
        if (m - n == 1)
            cout << " piece ";
        else
            cout << " pieces ";
        cout << "of chicken left over!\n";
    } else {
        cout << "needs ";
        cout << n - m;
        cout << " more ";
        if (n - m == 1)
            cout << "piece ";
        else
            cout << "pieces ";
        cout << "of chicken!\n";
    }
}
