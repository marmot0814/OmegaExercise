#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> cnt(1005, 0);
    for (int i = 0 ; i < n ; i++) {
        int num; cin >> num;
        cnt[num]++;
    }
    vector<pair<int, int> > data;
    int pos = 0;
    for (int i = 0 ; i < 1004 ; i++) {
        if (cnt[i] == 0 && cnt[i + 1] != 0)
            pos = i + 1;
        else if (cnt[i] != 0 && cnt[i + 1] == 0)
            data.push_back({pos, i});
    }
    for (auto &p : data) {
        if (p.second - p.first > 1) 
            cout << p.first << '-' << p.second;
        else if (p.second - p.first == 1)
            cout << p.first << ' ' << p.second;
        else cout << p.first;
        cout << ' ';
    }
    cout << '\n';
}
