#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int E, M, P, L, R, S, N;
    while (cin >> M >> P >> L >> E >> R >> S >> N) {
        for (int i = 0 ; i < N ; i++) {
            int tmp_p = P;
            P = L / R;
            L = E * M;
            M = tmp_p / S;
        }
        cout << M << '\n';
    }
}
