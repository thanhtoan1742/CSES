#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const int maxH = 25;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
int a[maxN];
vector<int> adj[maxN];

int h[maxN];
int dep[maxN];
int asc[maxN][maxH];

int csp = 1;
int dsp[maxN];
int dsh[maxN];

ll fen[maxN];

void DFS(int u = 1, int p = 0) {
    dep[u] = 1;
    asc[u][0] = p;
    for (int i = 1; i < maxH; ++i)
        asc[u][i] = asc[asc[u][i - 1]][i - 1];

    for (int v: adj[u]) {
        if (p == v)
            continue;

        h[v] = h[u] + 1;
        DFS(v, u);
        dep[u] = max(dep[u], dep[v]);
    }
}

void HLD(int u = 1) {
    dsp[u] = csp++;
    sort(adj[u].begin(), adj[u].end(), [](int x, int y) {
        return dep[x] > dep[y];
    });

    bool first = 1;
    for (int v: adj[u]) {
        if (v == asc[u][0])
            continue;

        if (!first)
            dsh[v] = v;
        else {
            first = 0;
            dsh[v] = dsh[u];
        }
        HLD(v); 
    }
}

void add_fenwick(int u, ll val) {
    for (; u <= n; u += u & -u)
        fen[u] += val;
}

ll get_fenwick(int u) {
    ll res = 0;
    for (; u; u -= u & -u)
        res += fen[u];
    return res;
}

void update(int u, ll val) {
    add_fenwick(dsp[u], val);
}

ll get(int u) {
    ll res = 0;
    while (u) {
        int h = dsh[u];
        res += get_fenwick(dsp[u]) - get_fenwick(dsp[h] - 1);
        u = asc[h][0];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    h[1] = 1;
    DFS();
    
    dsh[1] = 1;
    HLD();

    for (int i = 1; i <= n; ++i)
        update(i, a[i]);

    while (q--) {
        int t, u;
        cin >> t >> u;
        if (t == 1) {
            int x;
            cin >> x;
            update(u, x - a[u]);
            a[u] = x;
        }
        else {
            cout << get(u) << '\n';
        }

    }

}
