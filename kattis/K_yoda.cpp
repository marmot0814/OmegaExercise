#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string n, m; cin >> n >> m;
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    string x, y;
    for (int i = 0 ; i < (int)min(n.size(), m.size()) ; i++) {
        if (n[i] < m[i])
            y += m[i];
        else if (n[i] > m[i])
            x += n[i];
        else
            y += m[i], x += n[i];
    }
    if (n.size() < m.size())
        for (int i = n.size() ; i < (int)m.size() ; i++)
            y += m[i];
    else 
        for (int i = m.size() ; i < (int)n.size() ; i++)
            x += n[i];
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if ((int)x.size() == 0) {
        stringstream ss; ss << y;
        int tmp; ss >> tmp;
        cout << "YODA\n" << tmp << '\n';
    } else if ((int)y.size() == 0) {
        stringstream ss; ss << x;
        int tmp; ss >> tmp;
        cout << tmp << "\nYODA\n";
    } else {
        stringstream ss; ss << x << '\n' << y;
        int a, b; ss >> a >> b;
        cout << a << '\n' << b << '\n';
    }


}
