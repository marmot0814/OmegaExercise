#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
int trans(char c) {
    if (isdigit(c)) return c - '0';
    if (!isalpha(c)) return 0;
    if ('Q' < c) c--;
    return (c - 'A') / 3 + 2;
}
const int MAXLEN = 1e5 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        bool legal = false;
        unordered_map<int, int> cnt;
        for (int i = 0 ; i < n ; i++) {
            char s[MAXLEN]; cin >> s;
            int output = 0;
            for (int i = 0 ; s[i] ; i++) {
                char c = s[i];
                if (c == '-') continue;
                output *= 10;
                output += trans(c);
            }
            cnt[output]++;
            if (cnt[output] == 2) legal = true;
        }
        if (!legal) {
            cout << "No duplicates.\n\n";
            continue;
        }
        vector<pair<int, int> > data;
        for (auto &p : cnt) if (p.second >= 2) data.push_back(p);
        sort(data.begin(), data.end());
        for (auto &p : data) {
            cout << setw(3) << setfill('0') << p.first / 10000;
            cout << '-' << setw(4) << setfill('0') << p.first % 10000 << ' ';
            cout << p.second << '\n';
        }
        if (t) cout << '\n';
    }
}
