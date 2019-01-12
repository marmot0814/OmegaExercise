#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        int x, y; cin >> x >> y;
        while (n--) {
            int a, b; cin >> a >> b;
            if (a == x || b == y) {
                cout << "divisa\n";
            } else {
                if (a > x)
                    if (b > y) cout << "NE\n";
                    else cout << "SE\n";
                else
                    if (b > y) cout << "NO\n";
                    else cout << "SO\n";
            } 
        }
    }
}
