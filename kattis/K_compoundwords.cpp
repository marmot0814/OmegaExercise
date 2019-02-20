#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<string> data;
    string s; while (cin >> s) data.push_back(s);
    set<string> app;
    for (int i = 0 ; i < (int)data.size() ; i++)
        for (int j = i + 1 ; j < (int)data.size() ; j++)
            app.insert(data[i] + data[j]),
            app.insert(data[j] + data[i]);
    for (auto &str : app)
        cout << str << '\n';
}
