#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int main() {
    int n; LL t; cin >> n >> t;
    LL A, B, C; vector<LL> data(n);
    cin >> A >> B >> C >> data[0];
    for (int i = 1 ; i < n ; i++)
        data[i] = (A * data[i - 1] + B) % C + 1;
    sort(data.begin(), data.end());
    LL ans = 0, pen = 0, total = 0;
    for (int i = 0 ; i < n ; i++) {
        if (total + data[i] >= t) break;
        ans++; total += data[i];
        pen += total; pen %= MOD;
    }
    cout << ans << ' ' << pen << '\n';
}
