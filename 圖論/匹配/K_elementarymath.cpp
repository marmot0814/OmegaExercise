#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e4 + 5;
const int MAXM = 2500 * 2500 * 5;
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
#define F first
#define S second
typedef pair<LL, LL> pii;
map<LL, int> ID;
vector<LL> DATA;
int getID(LL x) {
    int sz = ID.size();
    if (!ID.count(x))
        ID[x] = sz, DATA.push_back(x);
    return ID[x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data) { 
        cin >> p.F >> p.S;
        getID(p.F + p.S);
        getID(p.F - p.S);
        getID(p.F * p.S);
    }
    Graph *sol = new Graph(n + ID.size() + 2);
    for (int i = 0 ; i < n ; i++) {
        sol->addEdge(i + 1, n + 1 + getID(data[i].F + data[i].S), 1);
        sol->addEdge(i + 1, n + 1 + getID(data[i].F - data[i].S), 1);
        sol->addEdge(i + 1, n + 1 + getID(data[i].F * data[i].S), 1);
    }
    for (int i = 0 ; i < n ; i++)
        sol->addEdge(0, i + 1, 1);
    for (int i = 0 ; i < (int)ID.size() ; i++) 
        sol->addEdge(n + 1 + i, n + ID.size() + 1, 1);
    LL flow = sol->maxFlow(0, n + ID.size() + 1);
    if (flow < n) {
        cout << "impossible\n";
    } else {
        vector<LL> ans;
        for (int i = 0 ; i < n * 3 ; i++) {
            if (sol->_memE[i * 2].f == 1)
                ans.push_back(DATA[sol->_memE[i * 2].v - sol->_memN - n - 1]);
        }
        for (int i = 0 ; i < n ; i++) {
            if (data[i].F + data[i].S == ans[i])
                cout << data[i].F << " + " << data[i].S << " = " << ans[i] << '\n';
            else if (data[i].F - data[i].S == ans[i])
                cout << data[i].F << " - " << data[i].S << " = " << ans[i] << '\n';
            else
                cout << data[i].F << " * " << data[i].S << " = " << ans[i] << '\n';
        }
    }

}
