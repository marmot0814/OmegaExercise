#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int minV = INF, minIdx = -1;
    int n; cin >> n; for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        if (v < minV) {
            minV = v; 
            minIdx = i;
        }
    }
    cout << minIdx << '\n';
}
