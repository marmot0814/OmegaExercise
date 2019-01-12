#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int maxV = -INF, minV = INF;
        while (n--) {
            int num; cin >> num;
            maxV = max(maxV, num);
            minV = min(minV, num);
        }
        cout << 2 * (maxV - minV) << '\n';
    }
}
