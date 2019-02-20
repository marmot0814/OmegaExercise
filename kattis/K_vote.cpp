#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int maxV = -1, maxIdx = -1, cnt = 0, sum = 0;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v; sum += v;
            if (maxV < v) {
                maxV = v;
                maxIdx = i + 1;
                cnt = 1;
            } else if (maxV == v) {
                cnt++;
            }
        }
        if (cnt == 1) {
            if (maxV * 2 > sum)
                cout << "majority ";
            else
                cout << "minority ";
            cout << "winner ";
            cout << maxIdx << '\n';
        } else
            cout << "no winner\n";
    }
}
