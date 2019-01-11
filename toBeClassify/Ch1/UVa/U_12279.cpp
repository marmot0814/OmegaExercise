#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int n; while (cin >> n && n) {
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            int num; cin >> num;
            if (num == 0) cnt--;
            else cnt++;
        }
        cout << "Case " << ++kase << ": " << cnt << '\n';
    }
}
