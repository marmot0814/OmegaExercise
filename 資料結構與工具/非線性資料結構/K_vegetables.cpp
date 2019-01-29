#include <bits/stdc++.h>
using namespace std;
struct Veg {
    int len, cut;
    double real() {
        return (double)len / cut;
    }
    bool operator < (const Veg &rhs) const {
        return (double)len / cut < (double)rhs.len / rhs.cut;
    }
};
bool check(vector<Veg> &data, double T) {
    return data.front().real() / data.back().real() > T;
}
int main() {
    double T; int n; cin >> T >> n;
    vector<Veg> data(n);
    for (auto &v : data) {
        cin >> v.len;
        v.cut = 1;
    }
    sort(data.begin(), data.end());
    int ans = 0;
    while (!check(data, T)) {
        ans++;
        data.back().cut++;
        sort(data.begin(), data.end());
    }
    cout << ans << '\n';
}
