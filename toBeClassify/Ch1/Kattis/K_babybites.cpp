#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    bool legal = true;
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        if (s[0] == 'm')
            continue;
        stringstream ss; ss << s;
        int tmp; ss >> tmp;
        if (tmp == i + 1)
            continue;
        legal = false;
    }
    if (legal)
        cout << "makes sense\n";
    else cout << "something is fishy\n";
}

