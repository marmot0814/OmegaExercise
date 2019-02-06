#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5e3 + 5;
const int MAXM = (MAXN * MAXN);
struct Graph{
    struct Node; struct Edge;
    int V;
    struct Node : vector<Edge*>{
        iterator cur; int d;
        Node(){ clear(); }
    }_memN[MAXN], *node[MAXN];
    struct Edge{
        Node *u, *v; 
        Edge *rev;
        LL c, f;
        Edge(){}
        Edge(Node *u, Node *v, LL c, Edge *rev) : u(u), v(v), c(c), f(0), rev(rev){}
    }_memE[MAXM], *ptrE;
    Graph(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    void addEdge(int _u, int _v, LL _c){
        *ptrE = Edge(node[_u], node[_v], _c, ptrE + 1);
        node[_u]->PB(ptrE++);
        *ptrE = Edge(node[_v], node[_u], 0, ptrE - 1); //  有向: 0, 無向: _c
        node[_v]->PB(ptrE++);
    }
    
    Node *s, *t;
    LL maxFlow(int _s, int _t){
        s = node[_s], t = node[_t];
        LL flow = 0;
        while (bfs()) {
            for (int i = 0 ; i < V ; i++)
                node[i]->cur = node[i]->begin();
            flow += dfs(s, INF);
        }
        return flow;
    }
    bool bfs(){
        for (int i = 0 ; i < V ; i++) node[i]->d = -1;
        queue<Node*> q; q.push(s); s->d = 0;
        while (q.size()) {
            Node *u = q.front(); q.pop();
            for (auto e : *u) {
                Node *v = e->v;
                if (!~v->d && e->c > e->f)
                    q.push(v), v->d = u->d + 1;
            }
        }
        return ~t->d;
    }
    LL dfs(Node *u, LL a){
        if (u == t || !a) return a;
        LL flow = 0, f;
        for (; u->cur != u->end() ; u->cur++) {
            auto &e = *u->cur; Node *v = e->v;
            if (u->d + 1 == v->d && (f = dfs(v, min(a, e->c - e->f))) > 0) {
                e->f += f; e->rev->f -= f;
                flow += f; a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, s; cin >> n >> q >> s;
    Graph *sol = new Graph(2 * n * q + n + 2);
    vector<int> toQ(s);
    for (auto &v : toQ) cin >> v, v--;
    vector<LL> Qsz(q);
    for (auto &v : Qsz) cin >> v;
    LL sum = 0;
    for (int i = 0 ; i < n ; i++) {
        LL c; cin >> c;
        sol->addEdge(2 * n * q + 1 + i, 2 * n * q + n + 1, c);
        for (int j = 0 ; j < s ; j++) {
            LL v; cin >> v;
            sum += v;
            sol->addEdge(0, 1 + i * q + toQ[j], v);
        }
        for (int j = 0 ; j < q ; j++) {
            sol->addEdge(1 + i * q + j, 1 + n * q + i * q + j, Qsz[j]);
            sol->addEdge(1 + n * q + i * q + j, 2 * n * q + 1 + i, INF);
            if (i != n - 1)
                sol->addEdge(1 + n * q + i * q + j, 1 + (1 + i) * q + j, INF);
        }
    }
    LL flow = sol->maxFlow(0, 2 * n * q + n + 1);
    if (flow != sum)
        cout << "impossible\n";
    else
        cout << "possible\n";
    delete sol;
}
