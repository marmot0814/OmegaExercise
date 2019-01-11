#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXH = 20;
const int MAXW = 15;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, b, h, w; while (cin >> n >> b >> h >> w) {
        int p[MAXH], a[MAXH][MAXW];
        for (int i = 0 ; i < h ; i++) {
            cin >> p[i];
            for (int j = 0 ; j < w ; j++)
                cin >> a[i][j];
        }
        int ans = INF;
        bool legal = false;
        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++) {
                if (a[i][j] >= n && b >= p[i] * n) {
                    legal = true;
                    ans = min(ans, p[i] * n);
                }
            }
        }
        if (legal)
            cout << ans << '\n';
        else
            cout << "stay home\n";
    }
}
