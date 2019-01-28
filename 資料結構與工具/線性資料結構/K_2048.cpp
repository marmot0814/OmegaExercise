#include <bits/stdc++.h>
using namespace std;
void trans(vector<vector<int> > &M) {
    vector<vector<int> > tmp = M;
    M.clear(); M.resize(4);
    for (int j = 3 ; ~j ; j--) 
        for (int i = 0 ; i < 4 ; i++)
            M[3 - j].push_back(tmp[i][j]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int> > M(4, vector<int>(4));
    for (auto &vv : M) for (auto &v : vv) cin >> v;
    int op; cin >> op;
    for (int i = 0 ; i < op ; i++)
        trans(M);
    
    vector<vector<int> > ans(4);
    for (int i = 0 ; i < 4 ; i++) {
        int tmp = -1;
        for (int j = 0 ; j < 4 ; j++) {
            if (M[i][j] == 0) continue;
            if (tmp == -1)
                tmp = M[i][j];
            else if (tmp == M[i][j]) {
                tmp += M[i][j];
                ans[i].push_back(tmp);
                tmp = -1;
            } else {
                ans[i].push_back(tmp);
                tmp = M[i][j];
            }
        }
        if (tmp != -1)
            ans[i].push_back(tmp);
        while (ans[i].size() < 4)
            ans[i].push_back(0);
    }
    for (int i = 0 ; i < (4 - op) % 4 ; i++)
        trans(ans);
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            cout << ans[i][j] << " \n"[j == 3];
}
