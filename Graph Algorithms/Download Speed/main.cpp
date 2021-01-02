#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 500 + 100;
const int maxM = 1000 + 100;
const long long maxFlow = 1e18;
 
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
 
struct Edge {
    int u, v, irev;
    long long c;
};
 
int n, m;
Edge e[maxM*2];
vector<int> adj[maxN];
 
int lev[maxN];
 
vector<int> path;
 
bool find_flow() {
    fill(lev + 1, lev + 1 + n, 0);
    queue<int> q;
    lev[1] = 1;
    q.push(1);
 
    while (q.size()) {
        int u = q.front();
        q.pop();
 
        if (u == n) 
            return 1;
 
        for (int i: adj[u])
            if (e[i].c && !lev[e[i].v]) {
                lev[e[i].v] = lev[u] + 1;
                q.push(e[i].v);
            }
    }
 
    return 0; 
}
 
long long add_flow(int u = 1, long long inflow = maxFlow) {
    if (u == n) 
        return inflow;
    if (inflow == 0)
        return 0;

    long long og_inflow = inflow;
 
    for (int i: adj[u])
        if (lev[e[i].v] == lev[u] + 1) {
            long long t = add_flow(e[i].v, min(inflow, e[i].c));
            e[i].c -= t;
            e[e[i].irev].c += t;
            inflow -= t;
        }
 
    return og_inflow - inflow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        
        e[i] = {x, y, i + m, c};
        e[i + m] = {y, x, i, 0};
        adj[x].push_back(i);
        adj[y].push_back(i + m);
    }
 
    long long flow = 0;
    while (find_flow())
        flow += add_flow();
    
    cout << flow << '\n';
}