#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if (n % 2) {
        for (auto &c : a)
            if (c == '0')
                c = '1';
            else
                c = '0';
    }
    if (a == b)
        cout << "Deletion succeeded\n";
    else
        cout << "Deletion failed\n";
}
