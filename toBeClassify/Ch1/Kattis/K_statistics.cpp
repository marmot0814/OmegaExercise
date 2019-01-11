#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int n; while (cin >> n) {
        int maxV = -INF, minV = INF;
        while (n--) {
            int num; cin >> num;
            maxV = max(maxV, num);
            minV = min(minV, num);
        }
        cout << "Case " << ++kase << ": " << minV << ' ' << maxV << ' ' << maxV - minV << '\n';
    }
}
