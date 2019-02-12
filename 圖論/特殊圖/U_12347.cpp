#include <bits/stdc++.h>
using namespace std;
struct Node {
    int v; Node *l, *r;
    Node (int _v) : v(_v) {}
}*rt;
void insert(Node *&u, int v) {
    if (!u) u = new Node(v);
    else if (v < u->v) {
        if (u->l) insert(u->l, v);
        else u->l = new Node(v);
    } else {
        if (u->r) insert(u->r, v);
        else u->r = new Node(v);
    }
}
void print(Node *u) {
    if (!u) return ;
    print(u->l);
    print(u->r);
    cout << u->v << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v; while (cin >> v)
        insert(rt, v);
    print(rt);

}
