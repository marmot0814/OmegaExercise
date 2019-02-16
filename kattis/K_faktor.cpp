#include <bits/stdc++.h>
using namespace std;
int check(int pro, int A, int I) {
    while (ceil((pro - 1) / double(A)) >= I)
        pro--;
    return pro;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int A, I; cin >> A >> I;
    int ans = A * I;
    cout << check(ans, A, I) << '\n';
}
