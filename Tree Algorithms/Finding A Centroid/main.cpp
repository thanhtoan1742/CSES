#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
vector<int> adj[maxN];

int ss[maxN];
int res;

void DFS(int u = 1, int p = 0) {
    ss[u] = 1;
    for (int v: adj[u]) {
        if (v == p) 
            continue;

        DFS(v, u);
        ss[u] += ss[v];
    }
}

void find_centroid(int u = 1, int p = 0) {
    auto it = max_element(adj[u].begin(), adj[u].end(), [](int u, int v) {
        return ss[u] < ss[v];
    });
    if (it != adj[u].end() && ss[*it] <= n/2) 
        res = u;

    for (int v: adj[u]) {
        if (v == p) 
            continue;

        ss[u] -= ss[v];
        ss[v] += ss[u];
        find_centroid(v, u);
        ss[v] -= ss[u];
        ss[u] += ss[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS();
    res = 1;
    find_centroid();
    cout << res << '\n';
}