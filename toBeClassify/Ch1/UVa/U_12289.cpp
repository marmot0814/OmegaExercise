#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string data[] = {"one", "two", "three"};
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        for (int i = 0 ; i < 3 ; i++) {
            int cnt = 0;
            for (int j = 0 ; j < min(data[i].size(), s.size()) ; j++) {
                if (data[i][j] != s[j])
                    cnt++;
            }
            if (cnt <= 1) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}
