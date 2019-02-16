#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef unsigned long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int b, v; while (cin >> b >> v) {
        vector<pair<string, int> > var;
        for (int i = 0 ; i < v ; i++) {
            string name; cin >> name;
            int n; cin >> n;
            var.push_back({name, n});
        }
        map<string, LL> data;
        for (int i = 0 ; i < v ; i++) {
            for (int j = 0 ; j < var[i].S ; j++) {
                for (int k = 0 ; k < b ; k++) {
                    char num; cin >> num;
                    data[var[i].F] *= 2;
                    data[var[i].F] += num - '0';
                }
            }
        }
        int q; cin >> q;while (q--) {
            string name; cin >> name;
            cout << name << "=";
            if (data.count(name))
                cout << data[name];
            cout << '\n';
        }
    }
}
