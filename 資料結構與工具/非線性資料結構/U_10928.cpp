#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> cnt(n);
        string input; getline(cin, input);
        for (int i = 0 ; i < n ; i++) {
            getline(cin, input);
            stringstream ss; ss << input;
            int num;
            while (ss >> num) cnt[i]++;
        }
        int minV = INF;
        for (int i = 0 ; i < n ; i++)
            minV = min(minV, cnt[i]);

        bool first = true;
        for (int i = 0 ; i < n ; i++) {
            if (cnt[i] == minV) {
                if (first) first = false; else cout << ' ';
                cout << i + 1;
            }
        }
        cout << '\n';

    }
}
