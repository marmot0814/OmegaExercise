#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const int MAXN = 250 + 5;
const int MAXM = MAXN * MAXN / 2;
struct Graph {
    struct Node; struct Edge;
    int V;
    struct Node : vector<Edge*> {
        Node *p, *s, *m;
        int S, v;
        Node() {
            clear(), S = v = -1, s = p = m = NULL;
        }
    }_memN[MAXN], *node[MAXN];
    struct Edge {
        Node *v;
        Edge(Node *v = NULL) : v(v) {}
    }_memE[MAXM], *ptrE;
    Graph(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    void addEdge(int u, int v) {
        node[u]->PB(new (ptrE++) Edge(node[v]));
        node[v]->PB(new (ptrE++) Edge(node[u]));
    }
    inline int maxMatch() {
        int ans = 0;
        for (int i = 0 ; i < V ; i++)
            if (!node[i]->m && bfs(node[i]))
                ans++;
        return ans;
    }
    inline bool bfs(Node *u) {
        for (int i = 0 ; i < V ; i++)
            node[i]->s = node[i], node[i]->S = -1;
        queue<Node*> q; q.push(u), u->S = 0;
        while (q.size()) {
            u = q.front(); q.pop();
            for (auto e : *u) {
                Node *v = e->v;
                if (!~v->S) {
                    v->p = u; v->S = 1;
                    if (!v->m) return augment(u, v);
                    q.push(v->m), v->m->S = 0;
                }else if (!v->S && v->s != u->s) {
                    Node *l = LCA(v->s, u->s);
                    flower(v, u, l, q);
                    flower(u, v, l, q);
                }
            }
        }
        return false;
    }
    inline bool augment(Node *u, Node *v) {
        for (Node *l; u; v = l, u = v ? v->p : NULL) {
            l = u->m;
            u->m = v;
            v->m = u;
        }
        return true;
    }
    inline Node* LCA(Node *u, Node *v) {
        static int t = 0;
        for (++t ; ; swap(u, v)) {
            if (!u) continue;
            if (u->v == t) return u;
            u->v = t;
            u = u->m; if (!u) continue;
            u = u->p; if (!u) continue;
            u = u->s;
        }
    }
    inline void flower(Node *u, Node *v, Node *l, queue<Node*> &q) {
        while (u->s != l) {
            u->p = v;
            v = u->m;
            if (v->S == 1) q.push(v), v->S = 0;
            u->s = v->s = l;
            u = v->p;
        }
    }
};
int main() {
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int lgn; cin >> lgn; int n = (1 << lgn);
        vector<vector<LL> > data(n, vector<LL>(n));
        for (int i = 0 ; i < n - 1 ; i++)
            for (int j = i + 1 ; j < n ; j++)
                cin >> data[i][j];
        LL L = 0, R = 1e9 + 7;
        while (R - L > 1) {
            LL M = (L + R) >> 1;
            Graph *sol = new Graph(n);
            for (int i = 0 ; i < n - 1 ; i++)
                for (int j = i + 1 ; j < n ; j++)
                    if (data[i][j] >= M)
                        sol->addEdge(i, j);
            LL res = sol->maxMatch();
            if (res == n / 2)
                L = M;
            else
                R = M;
        }
        cout << L << '\n';
    }
}
