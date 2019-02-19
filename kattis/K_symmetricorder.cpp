#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, kase = 0; while (cin >> n && n) {
        cout << "SET " << ++kase << '\n';
        vector<string> data(n);
        for (auto &s : data)
            cin >> s;
        for (int i = 0 ; i < n ; i += 2)
            cout << data[i] << '\n';
        for (int i = n - 1 - n % 2 ; i >= 0 ; i -= 2)
            cout << data[i] << '\n';
    }
}
