#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int cnt = 0, sum = 0;
    for (int i = 0 ; i < n ; i++) {
        int num; cin >> num;
        if (num < 0) continue;
        cnt++; sum += num;
    }
    cout << fixed << setprecision(20) << double(sum) / cnt << '\n';
}
