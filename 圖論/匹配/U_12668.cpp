#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5e4 + 5;
const int MAXM = 5e4 + 5;
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
    int n; while (cin >> n) {
        vector<vector<char> > G(n, vector<char>(n));
        for (auto &vv : G) for (auto &v : vv) cin >> v;
        vector<vector<int> > r(n, vector<int>(n, -1));
        vector<vector<int> > c(n, vector<int>(n, -1));
        int idx = 1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (G[i][j] == 'X')
                    idx++;
                else {
                    r[i][j] = idx;
                }
            }
            idx++;
        }
        int c_s = idx;
        for (int j = 0 ; j < n ; j++) {
            for (int i = 0 ; i < n ; i++) {
                if (G[i][j] == 'X')
                    idx++;
                else {
                    c[i][j] = idx;
                }
            }
            idx++;
        }
        Graph *sol = new Graph(idx + 1);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (G[i][j] == 'X')
                    continue;
                sol->addEdge(r[i][j], c[i][j], 1);
            }
        }
        for (int i = 1 ; i < c_s ; i++)
            sol->addEdge(0, i, 1);
        for (int i = c_s ; i < idx ; i++)
            sol->addEdge(i, idx, 1);
        cout << sol->maxFlow(0, idx) << '\n';
        delete sol;
        
    }
}
