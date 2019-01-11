#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t; while (t--) {
        string name, stu, bir; int n;
        cin >> name >> stu >> bir >> n;
        vector<int> stus, birs;
        for (int i = 0 ; i < stu.size() ; i++)
            if (stu[i] == '/')
                stu[i] = ' ';
        for (int i = 0 ; i < bir.size() ; i++)
            if (bir[i] == '/')
                bir[i] = ' ';
        stringstream ss;
        ss.clear(); ss << stu;
        int tmp;
        while (ss >> tmp)
            stus.push_back(tmp);
        ss.clear(); ss << bir;
        while (ss >> tmp)
            birs.push_back(tmp);
        if (stus[0] >= 2010) {
            cout << name << ' ' << "eligible\n";
            continue;
        }
        if (birs[0] >= 1991) {
            cout << name << ' ' << "eligible\n";
            continue;
        }
        if (n > 40) {
            cout << name << ' ' << "ineligible\n";
            continue;
        }
        cout << name << ' ' << "coach petitions\n";

    }
}
