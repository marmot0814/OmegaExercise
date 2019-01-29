#include <bits/stdc++.h>
using namespace std;
int trans(int x) {
    char *p = (char*)&x;
    swap(p[0], p[3]);
    swap(p[1], p[2]);
    return x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        cout << n << " converts to " << trans(n) << '\n';
    }
}
