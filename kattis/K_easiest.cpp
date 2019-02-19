#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n; while (cin >> n && n) {
        for (LL i = 11 ; ; i++) {
            LL tar = i * n;
            LL N = n;
            LL sum_tar = 0, sum_N = 0;
            while (N) {
                sum_N += N % 10;
                N /= 10;
            }
            while (tar) {
                sum_tar += tar % 10;
                tar /= 10;
            }
            if (sum_tar == sum_N) {
                cout << i << '\n';
                break;
            }
        }

    }
}
