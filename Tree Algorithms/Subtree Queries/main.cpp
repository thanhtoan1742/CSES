#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

struct Node {
    long long s, upd;
};

int n;
int a[maxN];
vector<int> adj[maxN];

int p[maxN];
int h[maxN];

int nds = 1;
int dsp[maxN];
int dsh[maxN];

Node st[maxN*4];

void apply_ST(int i, long long upd) {
    st[i].s += upd;
    st[i].upd += upd;
}

void down_ST(int i) {
    apply_ST(2*i, st[i].upd);
    apply_ST(2*i + 1, st[i].upd);
    st[i].upd = 0;
}

void update_ST(int u, int v, long long upd, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) {
        apply_ST(i, upd);
        return;
    }

    if (v < l || r < u)
        return;

    down_ST(i);
    int m = (l + r)/2;
    update_ST(u, v, upd, 2*i, l, m);
    update_ST(u, v, upd, 2*i + 1, m + 1, r);
    st[i].s = st[2*i].s + st[2*i + 1].s;
}

long long get_ST(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) 
        return st[i].s;

    if (v < l || r < u)
        return 0;

    down_ST(i);
    int m = (l + r)/2;
    long long res = get_ST(u, v, 2*i, l, m) + get_ST(u, v, 2*i + 1, m + 1, r);
    st[i].s = st[2*i].s + st[2*i + 1].s;
    return res;
}

void DFS(int u = 1) {
    h[u] = 1;
    for (int v: adj[u]) {
        if (v == p[u])
            continue;

        p[v] = u;
        DFS(v);
        maximize(h[u], h[v] + 1);
    }    
}

void HLD(int u = 1, int is_head = 1) {
    dsp[u] = nds++;
    if (is_head) 
        dsh[u] = u;

    sort(adj[u].begin(), adj[u].end(), [](int u, int v) {
        return h[u] > h[v];
    });

    bool first = 1;
    for (int v: adj[u]) {
        if (v == p[u])
            continue;

        if (first) {
            first = 0;
            dsh[v] = dsh[u];
            HLD(v, 0);
        }
        else
            HLD(v, 1);
    }
}

long long get(int i) {
    return get_ST(dsp[i], dsp[i]);
}

void update(int i, long long s) {
    while (i) {
        update_ST(dsp[dsh[i]], dsp[i], s);
        i = p[dsh[i]];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
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
    
    HLD();

    for (int i = 1; i <= n; ++i)
        update(i, a[i]);
        
    while (m--) {
        int q, i;
        cin >> q >> i;
        if (q == 1) {
            long long x;
            cin >> x;
            update(i, x - a[i]);
            a[i] = x;
        }
        else 
            cout << get(i) << '\n';
    }
}
