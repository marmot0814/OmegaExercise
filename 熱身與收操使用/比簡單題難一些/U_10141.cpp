#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9 + 7;
struct User {
    string name;
    double val;
    int num;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0; bool first = true;
    int n, m; while (cin >> n >> m && (n || m)) {
        if (first) first = false;
        else cout << '\n';
        cout << "RFP #" << ++kase << '\n';
        string tmp; getline(cin, tmp); 
        while (n--) getline(cin, tmp);
        User tar{"123", INF, 0};
        while (m--) {
            string name;
            getline(cin, name);
            double val;
            int num;
            cin >> val >> num;
            getline(cin, tmp);
            for (int i = 0 ; i < num ; i++)
                getline(cin, tmp);
            if (num > tar.num) {
                tar = {name, val, num};
            } else if (num == tar.num && val < tar.val) {
                tar = {name, val, num};
            }
        }
        cout << tar.name << '\n';
    }
}
