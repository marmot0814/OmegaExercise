#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long cnt = 2;
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++)
        cnt *= 2, cnt--;
    cout << cnt * cnt << '\n';
}
