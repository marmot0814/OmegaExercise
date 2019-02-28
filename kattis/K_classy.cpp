#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<pss> data;
        int maxV = 0;
        while (n--) {
            string name, level, tmp; cin >> name >> level >> tmp;
            for (auto &c : level)
                if (c == '-')
                    c = ' ';
            stringstream ss; ss << level;
            string res;
            while (ss >> tmp) {
                if (tmp[0] == 'u')
                    res += '0';
                else if (tmp[0] == 'm')
                    res += '1';
                else
                    res += '2';
            }
            reverse(res.begin(), res.end());
            data.push_back({res, name});
            maxV = max(maxV, (int)res.size());
        }
        for (auto &p : data) {
            while ((int)p.first.size() != maxV)
                p.first += '1';
        }
        sort(data.begin(), data.end());
        for (auto &p : data)
            cout << p.second.substr(0, p.second.size() - 1) << '\n';
        cout << "==============================\n";
    }
}
