#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        int cnt = 0, sum = 0;
        do {
            sum *= 10;
            sum++;
            sum %= n;
            cnt++;
        } while (sum);
        cout << cnt << '\n';
    }
}
