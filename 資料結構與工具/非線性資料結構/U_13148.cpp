#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    set<LL> app;
    for (LL i = 1 ; i*i*i*i*i*i < 100000000 ; i++) {
        app.insert(i*i*i*i*i*i);
    }
    int n; while (cin >> n && n) {
        if (app.count(n))
            cout << "Special\n";
        else
            cout << "Ordinary\n";
    }
}
