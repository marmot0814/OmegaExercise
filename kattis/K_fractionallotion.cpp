#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    string s; while (cin >> s) {
        s = s.substr(2, s.size() - 2);
        stringstream ss; ss << s;
        long long n, ans = 0; ss >> n;
        for (long long i = n + 1 ;; i++) {
            if ((n * i) % (i - n))
                continue;
            long long y = n * i / (i - n);
            ans++;
            if (i >= y)
                break;
        }
        cout << ans << '\n';
    }
}
/*
1/x + 1/y = 1/n

(x + y) * n = xy
nx + ny = xy
nx / (x - n) = y
*/
