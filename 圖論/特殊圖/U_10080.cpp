#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<double, double> pii;
typedef vector<pii> vpii;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e3 + 5;
const int MAXM = (MAXN * MAXN) / 2;
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
    int n, m, s, v; while (cin >> n >> m >> s >> v) {
        vpii pos(n);
        for (auto &p : pos) cin >> p.F >> p.S;
        vpii hole(m);
        for (auto &p : hole) cin >> p.F >> p.S;
        Graph *sol = new Graph(n + m + 2);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                double dist = hypot(pos[i].F - hole[j].F, pos[i].S - hole[j].S);
                if (s * v < dist) continue;
                sol->addEdge(i + 1, j + n + 1, 1);
            }
        }
        for (int i = 0 ; i < n ; i++)
            sol->addEdge(0, i + 1, 1);
        for (int i = 0 ; i < m ; i++)
            sol->addEdge(i + n + 1, n + m + 1, 1);
        cout << n - sol->maxFlow(0, n + m + 1) << '\n';
        delete sol;
    }
			
}
