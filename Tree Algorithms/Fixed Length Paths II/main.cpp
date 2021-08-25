#include <bits/stdc++.h>
#include <numeric>

using namespace std;

template <typename T>
using vec = vector<T>;
using ll = long long;

const int maxN = 2e5 + 100;

int n, k1, k2;
vec<int> adj[maxN];

bool removed[maxN];
int stsz[maxN];

int max_d;
int cnt[maxN], scnt[maxN];
ll res;

void read_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k1 >> k2;
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

void count_path(int u, int p = -1, bool filling = true, int d = 0) {
    if (d > k2)
        return;

    max_d = max(max_d, d);
    if (filling)
        cnt[d]++;
    else {
        int i = max(0, k1 - d);
        int j = (k2 - d);
        res += scnt[i] - scnt[j + 1];
        // res += accumulate(f + i, f + j + 1, 0);
    }

    for (int v: adj[u]) {
        if (removed[v] || v == p)
            continue;

        count_path(v, u, filling, d + 1);
    }
    scnt[d] = scnt[d + 1] + cnt[d];
}

void centroid_decompose(int u = 1) {
    int root = find_centroid(u);
    removed[root] = true;

	fill(cnt + 1, cnt + max_d + 1, 0); cnt[0] = 1;
    fill(scnt + 1, scnt + max_d + 1, 0); scnt[0] = 1;
    max_d = 0;
    for (int v: adj[root])
        if (!removed[v]) {
            count_path(v, root, false, 1);
            count_path(v, root, true, 1);
            scnt[0] = scnt[1] + cnt[0];
        }

    for (int v: adj[root])
        if (!removed[v])
            centroid_decompose(v);
}

int main() {
    read_input();
    centroid_decompose();
    print_output();
}