#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    int n; cin >> n;
    map<string, int> cnt;
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        cnt[s]++;
    }
    int minV = INF;
    for (auto &p : cnt) 
        minV = min(minV, p.second);
    for (auto &p : cnt)
        if (p.second == minV)
            cout << p.first << '\n';
}
