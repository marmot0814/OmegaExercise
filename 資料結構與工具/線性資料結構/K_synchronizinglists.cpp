#include <bits/stdc++.h>
using namespace std;
struct P {
    int a, b;
};
int main() {
    bool first = true;
    int n; while (cin >> n && n) {
        if (first) first = false; else cout << '\n';
        vector<P> data(n);
        int idx = 0;
        for (auto &p : data) {
            cin >> p.a;
            p.b = idx++;
        }
        sort(data.begin(), data.end(), [](P x, P y){
            return x.a < y.a;
        });
        vector<P> tar(n);
        for (auto &p : tar)
            cin >> p.a;
        sort(tar.begin(), tar.end(), [](P x, P y) { return x.a < y.a; });
        idx = 0;
        for (auto &p : tar)
            p.b = data[idx++].b;
        sort(tar.begin(), tar.end(), [](P x, P y) { return x.b < y.b; });
        for (auto &p : tar)
            cout << p.a << '\n';
    }
}
