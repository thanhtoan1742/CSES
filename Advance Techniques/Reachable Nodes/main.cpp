#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;

const int maxN = 5e4 + 100;

int n;
vector<int> adj[maxN];
int deg[maxN];

bitset<maxN> st[maxN];

void DFS(int u) {
    deg[u]--;
    st[u].set(u);
    for (int v: adj[u]) {
        deg[v]--;
        st[v] |= st[u];
        if (deg[v] == 0)
            DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        deg[x]++;
    }

    for (int u = 1; u <= n; ++u)
        if (deg[u] == 0)
            DFS(u);

    for (int i = 1; i <= n; ++i) 
        cout << st[i].count() << " ";
    cout << "\n";
}
