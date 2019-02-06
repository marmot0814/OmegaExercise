#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<vector<int> > d_bi(n, vector<int>(n, INF));
        for (int i = 0 ; i < n ; i++) d_bi[i][i] = 0;
        string input; getline(cin, input);
        for (int i = 0 ; i < n ; i++) {
            getline(cin, input);
            stringstream ss; ss << input;
            int idx; ss >> idx;
            int v; while (ss >> v) v--, d_bi[i][v] = 1;
        }
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    d_bi[i][j] = min(d_bi[i][j], d_bi[i][k] + d_bi[k][j]);
        vector<vector<int> > d_dir(n, vector<int>(n, INF));
        for (int i = 0 ; i < n ; i++) d_dir[i][i] = 0;
        for (int i = 0 ; i < n ; i++) {
            getline(cin, input);
            stringstream ss; ss << input;
            int idx; ss >> idx;
            int v; while (ss >> v) v--, d_dir[i][v] = 1;
        }
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    d_dir[i][j] = min(d_dir[i][j], d_dir[i][k] + d_dir[k][j]);
        int A, B; cin >> A >> B;
        bool legal = true;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                if (d_bi[i][j] * A + B < d_dir[i][j])
                    legal = false;
        if (legal)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
