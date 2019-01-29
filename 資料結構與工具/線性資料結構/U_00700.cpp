#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int n; while (cin >> n && n) {
        cout << "Case #" << ++kase << ":\n";
        int ans = -1;
        vector<int> y, a, b;
        for (int i = 0 ; i < n; i++) {
            int Y, A, B; cin >> Y >> A >> B;
            y.push_back(Y);
            a.push_back(A);
            b.push_back(B);
        }
        for (int i = 0 ; i < 10000 ; i++) {
            bool legal = true;
            for (int j = 0 ; j < n && legal ; j++) {
                if (i < a[j]) { 
                    legal = false;
                } else if (a[j] + (i - a[j]) % (b[j] - a[j]) != y[j])
                    legal = false;
            }
            if (!legal) continue;
            ans = i; break;
        }
        if (~ans) cout << "The actual year is " << ans << ".\n";
        else cout << "Unknown bugs detected.\n";
        cout << '\n';
    }
}
