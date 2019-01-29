#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; while (cin >> n) {
        vector<string> data;
        int maxV = 0;
        for (int i = 0 ; i < n ; i++) {
            string name; cin >> name;
            data.push_back(name);
            maxV = max(maxV, (int)data[i].size());
        }
        sort(data.begin(), data.end());
        int cnt = 1;
        while (maxV + (maxV + 2) * (cnt) <= 60)
            cnt++;
        int rows = ceil((double)n / cnt);
        cout << "------------------------------------------------------------\n";
        for (int idx = 0 ; idx < rows ; idx++) {
            for (int i = idx ; i < n ; i += rows) {
                cout << data[i];
                if (i + rows < n) {
                    for (int x = 0 ; x < maxV + 2 - (int)data[i].size() ; x++)
                        cout << ' ';
                } else for (int x = 0 ; x < maxV - (int)data[i].size() ; x++)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
}
