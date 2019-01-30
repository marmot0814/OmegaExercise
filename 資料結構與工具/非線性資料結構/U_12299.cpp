#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int lgN = __lg(MAXN) + 5;
struct SegmentTree {
    struct Node {
        int L, R; 
        Node *l, *r;
        // data
        LL v;
        // tag
        Node (int _L = 0,int _R = 0) : L(_L), R(_R) {
            l = r = NULL;
        }
    }*rt, buf[lgN << 2], *ptr;
    LL *arr; int n;
    SegmentTree(LL *_arr, int _n) {
        arr = _arr, n = _n;
        rt = build(0, n);
    }
    ~SegmentTree() {
        remove(rt);
    }
    void remove(Node *u) {
        if (!u) return ;
        remove(u->r);
        remove(u->l);
        delete u;
    }
    Node* build(int L, int R) {
        Node *u = new Node(L, R);
        if (R - L == 1) {
            // basic data
            u->v = arr[L];
            return u;
        }
        int M = (R + L) >> 1;
        u->l = build(L, M);
        u->r = build(M, R);
        return pull(u);
    }
    Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        push(l); push(r);
        // pull function;
        u->v = min(l->v, r->v);
        return u;
    }
    void push(Node *u) {
        if (!u) return ;
        // push function
    }
    Node* query(int qL, int qR) {
        ptr = buf;
        return query(qL, qR, rt);
    }
    Node* query(int qL, int qR, Node *u) {
        if (u->R <= qL || qR <= u->L) return (Node*)NULL;
        if (qL <= u->L && u->R <= qR) return u;
        push(u);
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int x, int v) {
        return modify(x, x + 1, v, rt);
    }
    void modify(int mL, int mR, LL v, Node *u) {
        if (u->R <= mL || mR <= u->L) return ;
        if (mL <= u->L && u->R <= mR) {
            // modify function
            u->v = v;
            return ;
        }
        push(u);
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        pull(u);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    LL arr[MAXN];
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
    SegmentTree *sol = new SegmentTree(arr, n);
    string input; getline(cin, input);
    while (getline(cin, input)) {
        if (input[0] == 'q') {
            for (auto &c : input)
                if (!isdigit(c))
                    c = ' ';
            stringstream ss; ss << input;
            int l, r; ss >> l >> r;
            cout << sol->query(l - 1, r)->v << '\n';
        } else {
            for (auto &c : input)
                if (!isdigit(c))
                    c = ' ';
            stringstream ss; ss << input;
            vector<int> shi; int tmp;
            vector<LL> val;
            while (ss >> tmp) { 
                shi.push_back(tmp);
                val.push_back(sol->query(tmp - 1, tmp)->v);
            }
            shi.push_back(shi[0]);
            val.push_back(val[0]);
            for (int i = 0 ; i < (int)shi.size() - 1 ; i++)
                sol->modify(shi[i] - 1, val[i + 1]);
        }
    }
    delete sol;
}

