#include <bits/stdc++.h>
using namespace std;
bool checkCro(char target, vector<vector<char> > &B, int i, int j) {
    for (int x = i - 1 ; x >= 0 ; x--) {
        if (B[x][j] == '.')
            continue;
        if (B[x][j] == target)
            return true;
        break;
    }
    for (int x = i + 1 ; x < 8 ; x++) {
        if (B[x][j] == '.')
            continue;
        if (B[x][j] == target)
            return true;
        break;
    }
    for (int y = j - 1 ; y >= 0 ; y--) {
        if (B[i][y] == '.')
            continue;
        if (B[i][y] == target)
            return true;
        break;
    }
    for (int y = j + 1 ; y < 8 ; y++) {
        if (B[i][y] == '.')
            continue;
        if (B[i][y] == target)
            return true;
        break;
    }
    return false;
}
bool checkDia(char target, vector<vector<char> > &B, int i, int j) {
    int x, y;
    x = i - 1, y = j - 1;
    while (1) {
        if (x < 0 || y < 0)
            break;
        if (B[x][y] == '.') {
            x--, y--;
            continue;
        }
        if (B[x][y] == target)
            return true;
        break;
    }
    x = i - 1, y = j + 1;
    while (1) {
        if (x < 0 || y >= 8)
            break;
        if (B[x][y] == '.') {
            x--, y++;
            continue;
        }
        if (B[x][y] == target)
            return true;
        break;
    }
    x = i + 1, y = j + 1;
    while (1) {
        if (x >= 8 || y >= 8)
            break;
        if (B[x][y] == '.') {
            x++, y++;
            continue;
        }
        if (B[x][y] == target)
            return true;
        break;
    }
    x = i + 1, y = j - 1;
    while (1) {
        if (x >= 8 || y < 0)
            break;
        if (B[x][y] == '.') {
            x++, y--;
            continue;
        }
        if (B[x][y] == target)
            return true;
        break;
    }
    return false;
}
bool checkP(char target, vector<vector<char> > &B, int i, int j) {
    if (target == 'K') {
        if (i + 1 <  8 && j - 1 >= 0 && B[i + 1][j - 1] == 'K')
            return true;
        if (i + 1 <  8 && j + 1 <  8 && B[i + 1][j + 1] == 'K')
            return true;
    } else {
        if (i - 1 >= 0 && j - 1 >= 0 && B[i - 1][j - 1] == 'k')
            return true;
        if (i - 1 >= 0 && j + 1 <  8 && B[i - 1][j + 1] == 'k')
            return true;
    }
    return false;
}
bool checkR(char target, vector<vector<char> > &B, int i, int j) {
    return checkCro(target, B, i, j);
}
bool checkB(char target, vector<vector<char> > &B, int i, int j) {
    return checkDia(target, B, i, j);
}
bool checkQ(char target, vector<vector<char> > &B, int i, int j) {
    return checkCro(target, B, i, j) || checkDia(target, B, i, j);
}
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool checkN(char target, vector<vector<char> > &B, int i, int j) {
    for (int d = 0 ; d < 8 ; d++) {
        int x = i + dx[d], y = j + dy[d];
        if (x < 0 || x >= 8 || y < 0 || y >= 8)
            continue;
        if (B[x][y] == target)
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    while (1) {
        vector<vector<char> > B(8, vector<char>(8));
        bool end = true, isB = false;
        for (auto &vv : B) {
            for (auto &v : vv) {
                cin >> v;
                if (v != '.')
                    end = false;
            }
        }
        if (end) break;
        cout << "Game #" << ++kase << ": ";
        end = false;
        for (int i = 0 ; i < 8 ; i++) {
            for (int j = 0 ; j < 8 ; j++) {
                if (B[i][j] == '.') continue;
                switch (tolower(B[i][j])) {
                    case 'p':
                        if (checkP(islower(B[i][j]) ? 'K' : 'k', B, i, j))
                            end = true, isB = islower(B[i][j]);
                        break;
                    case 'r':
                        if (checkR(islower(B[i][j]) ? 'K' : 'k', B, i, j))
                            end = true, isB = islower(B[i][j]);
                        break;
                    case 'b':
                        if (checkB(islower(B[i][j]) ? 'K' : 'k', B, i, j))
                            end = true, isB = islower(B[i][j]);
                        break;
                    case 'q':
                        if (checkQ(islower(B[i][j]) ? 'K' : 'k', B, i, j))
                            end = true, isB = islower(B[i][j]);
                        break;
                    case 'n':
                        if (checkN(islower(B[i][j]) ? 'K' : 'k', B, i, j))
                            end = true, isB = islower(B[i][j]);
                        break;
                    default:
                        break;
                }
            }
        }
        if (end) {
            if (!isB) cout << "black";
            else cout << "white";
            cout << " king is in check.\n";
        } else cout << "no king is in check.\n";
    }
}
