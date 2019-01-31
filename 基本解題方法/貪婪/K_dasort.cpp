#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        vector<int> sorted = data;
        sort(sorted.begin(), sorted.end());
        int index = 0;
        for (int i = 0 ; i < n ; i++) {
            if (sorted[index] == data[i])
                index++;
        }
        cout << n - index << '\n';
    }
}
