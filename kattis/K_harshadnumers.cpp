#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = n ;; i++) {
        int x = i;
        int cnt = 0;
        while (x) 
            cnt += x % 10, x /= 10;
        if (i % cnt)
            continue;
        cout << i << '\n';
        break;
    }
}

