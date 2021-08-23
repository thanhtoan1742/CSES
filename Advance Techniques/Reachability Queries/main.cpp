#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >;
using ll = long long;

const ll maxN = 5e4 + 100;

int n;
vector<int> adj[maxN];

int nscc = 0;
int scc[maxN];

int tim;
int low[maxN], vis[maxN];
bool in_stack[maxN];
stack<int> st;

vector<int> scc_adj[maxN];
int deg[maxN];

bitset<maxN> rea[maxN];

void scc_visit(int u) {
    low[u] = vis[u] = tim++;
    st.push(u);
    in_stack[u] = 1;

    for (int v: adj[u])
        if (vis[v] == -1) {
            scc_visit(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
            low[u] = min(low[u], vis[v]);

    if (low[u] != vis[u])
        return;

    nscc++;
    while (1) {
        int v = st.top();
        st.pop();
        in_stack[v] = 0;
        scc[v] = nscc;

        if (v == u)
            break;
    }
}

void make_scc() {
    fill(vis + 1, vis + 1 + n, -1);
    fill(low + 1, low + 1 + n, -1);
    nscc = 0;

    tim = 0;
    for (int u = 1; u <= n; ++u)
        if (vis[u] == -1)
            scc_visit(u);
}

void DFS(int u) {
    deg[u]--;
    rea[u].set(u);

    for (int v: scc_adj[u]) {
        deg[v]--;
        rea[v] |= rea[u];
        if (deg[v] == 0)
            DFS(v);
    }
}

void make_rea() {
    for (int u = 1; u <= n; ++u)
        for (int v: adj[u])
            if (scc[u] != scc[v]) {
                deg[scc[u]]++;
                scc_adj[scc[v]].push_back(scc[u]);
            }

    for (int u = 1; u <= nscc; ++u)
        if (deg[u] == 0) 
            DFS(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, q;
    cin >> n >> m >> q;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    make_scc();
    make_rea();

    while (q--) {
        int x, y;
        cin >> x >> y;
        x = scc[x];
        y = scc[y];
        if (rea[x][y])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
