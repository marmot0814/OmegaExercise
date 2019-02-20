#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            data.push_back(v);
        }
        for (int i = 1 ; i < n - 1 ; i++) {
            if (data[i] >= data[i - 1] && data[i] >= data[i + 1] && data[i - 1] < data[i + 1]) {
                cout << i + 1 << '\n';
                break;
            }
            if (data[i] <= data[i - 1] && data[i] <= data[i + 1] && data[i - 1] < data[i + 1]) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}
