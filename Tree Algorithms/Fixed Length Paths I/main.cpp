#include <bits/stdc++.h>
 
using namespace std;
 
template <typename T>
using vec = vector<T>;
using ll = long long;
 
const int maxN = 2e5 + 100;
 
int n, k;
vec<int> adj[maxN];
 
bool removed[maxN];
int stsz[maxN];
 
struct {
    int root;
    int prev;
    int cur;
} f[maxN];
ll res;
 
void read_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
 
void print_output() {
    cout << res << "\n";
}
 
void cal_subtree_size(int u, int p = -1) {
    stsz[u] = 1;
    for (int v: adj[u]) {
        if (v == p || removed[v])
            continue;
 
        cal_subtree_size(v, u);
        stsz[u] += stsz[v];
    }
}
 
int find_centroid_dfs(int tsz, int u, int p = -1) {
    for (int v: adj[u]) {
        if (v == p || removed[v])
            continue;
 
        if (stsz[v]*2 > tsz)
            return find_centroid_dfs(tsz, v, u);
    }
 
    return u;
}
 
int find_centroid(int u) {
    cal_subtree_size(u);
    return find_centroid_dfs(stsz[u], u);
}
 
void count_path_dfs(int root, int u, int p = -1, int d = 0) {
    if (d > k)
        return;
 
    if (f[d].root != root) {
        f[d].root = root;
        f[d].cur = f[d].prev = 0;
    }
    if (f[k - d].root == root)
        res += f[k - d].prev;
    f[d].cur += 1;
    if (u == root) {
        f[0].cur = 0;
        f[0].prev = 1;
    }
 
    for (int v: adj[u]) {
        if (v == p || removed[v])
            continue;
 
        count_path_dfs(root, v, u, d + 1);
 
        if (u != root)
            continue;
        for (int i = 1; i <= k && f[i].root == root && f[i].cur != 0; ++i) {
            f[i].prev += f[i].cur;
            f[i].cur = 0;
        }
    }
}
 
void count_path(int root) {
    count_path_dfs(root, root);
}
 
void centroid_decompose(int u = 1) {
    int root = find_centroid(u);
    count_path(root);
 
    removed[root] = true;
    for (int v: adj[root])
        if (!removed[v])
            centroid_decompose(v);
}
 
int main() {
    read_input();
    centroid_decompose();
    print_output();
}