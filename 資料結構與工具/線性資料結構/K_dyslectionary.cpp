#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    vector<string> data; string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            if (first) first = false; else cout << '\n';
            sort(data.begin(), data.end());
            int maxV = 0;
            for (auto &s : data)
                maxV = max(maxV, (int)s.size());
            for (auto &s : data) {
                reverse(s.begin(), s.end());
                for (int i = 0 ; i < maxV - s.size() ; i++)
                    cout << ' ';
                cout << s << '\n';
            }
            data.clear();
            continue;
        }
        reverse(s.begin(), s.end());
        data.push_back(s);
    }
    if (first) first = false; else cout << '\n';
    sort(data.begin(), data.end());
    int maxV = 0;
    for (auto &s : data) maxV = max(maxV, (int)s.size());
    for (auto &s : data) {
        reverse(s.begin(), s.end());
        for (int i = 0 ; i < maxV - s.size() ; i++)
            cout << ' ';
        cout << s << '\n';
    }
}
