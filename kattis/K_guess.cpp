#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int L = 0, R = 1001;
    string res = "0";
    while (res[0] != 'c') {
        int M = (R + L) >> 1;
        cout << M << '\n' << flush;
        cin >> res;
        if (res[0] == 'h')
            L = M;
        if (res[0] == 'l')
            R = M;
    }
}
