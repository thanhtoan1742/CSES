#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
const int maxN = 2e5 + 100;
const int maxH = 25;
const int maxA = 1e9 + 100;
 
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int n;
int a[maxN];
vector<int> adj[maxN];
 
int h[maxN];
int ss[maxN];
int asc[maxN][maxH];
 
int csp = 0;
int dsp[maxN];
int dsh[maxN];
 
int st[maxN*2];
 
void build_st() {
    for (int i = 1; i <= n; ++i)
        st[dsp[i] + n] = a[i];

    for (int i = n - 1; i > 0; --i)
        st[i] = max(st[i << 1], st[i << 1|1]);
}
 
void singly_update_st(int u, int val) {
    for (st[u += n] += val; u > 1; u >>= 1)
        st[u >> 1] = max(st[u], st[u^1]);
}
 
int get_st(int u, int v) {
    int res = 0;
    for (u += n, v += n + 1; u < v; u >>= 1, v >>= 1) {
        if (u&1) 
            res = max(res, st[u++]);
        if (v&1)
            res = max(res, st[--v]);
    }
    return res;
}
 
void DFS(int u = 1, int p = 0) {
    ss[u] = 1;
    asc[u][0] = p;
    for (int i = 1; i < maxH; ++i)
        asc[u][i] = asc[asc[u][i - 1]][i - 1];
 
    for (int v: adj[u]) {
        if (p == v)
            continue;
 
        h[v] = h[u] + 1;
        DFS(v, u);
        ss[u] += ss[v];
    }
}
 
void HLD(int u = 1) {
    dsp[u] = csp++;
    sort(adj[u].begin(), adj[u].end(), [](int x, int y) {
        return ss[x] > ss[y];
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
 
int LCA(int u, int v) {
    if (h[u] > h[v])
        swap(u, v);
 
    for (int i = maxH - 1; i >= 0; --i)
        if (h[asc[v][i]] >= h[u])
            v = asc[v][i];
    if (u == v)
        return u;
 
    for (int i = maxH - 1; i >= 0; --i)
        if (asc[u][i] != asc[v][i]) {
            u = asc[u][i];
            v = asc[v][i];
        }
    return asc[u][0];
}
 
int get_HLD(int a, int u) {
    int res = 0;
    while (dsh[u] != dsh[a]) {
        int h = dsh[u];
        res = max(res, get_st(dsp[h], dsp[u]));
        u = asc[h][0];
    }
 
    return max(res, get_st(dsp[a], dsp[u]));
}
 
void update(int u, int val) {
    singly_update_st(dsp[u], val - a[u]);
    a[u] = val;
}
 
int get(int u, int v) {
    int a = LCA(u, v);
    if (a == u)
        return get_HLD(a, v);
    if (a == v)
        return get_HLD(a, u);
 
    return max(get_HLD(a, u), get_HLD(a, v));
}
 
int main() {
    auto total_time_s = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    h[1] = 1;
    DFS();
    dsh[1] = 1;
    HLD();
 
    build_st();
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, val;
            cin >> u >> val;
            update(u, val);
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << get(u, v) << ' ';
        }
    }
    auto total_time_t = high_resolution_clock::now();
    cerr << "total time: " << duration_cast<milliseconds>(total_time_t - total_time_s).count() << "ms\n";
}