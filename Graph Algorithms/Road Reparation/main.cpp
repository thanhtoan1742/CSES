#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;
const int maxM = 2e5 + 100;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

struct Edge {
    int u, v;
    long long w;

    Edge(int _u = 0, int _v = 0, long long _w = 0) 
    : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge& other) const & {
        return w < other.w;
    }
};

int n, m;
Edge e[maxM];

int root[maxN];

int get_root(int u) {
    if (!root[u]) return u;
    return root[u] = get_root(root[u]);
}

void Union(int u, int v) {
    root[v] = u;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e + m);


    long long res = 0;
    int c = 0;
    for (int i = 0; i <= m; ++i) {
        int u = get_root(e[i].u);
        int v = get_root(e[i].v);
        if (u == v) continue;

        res += e[i].w;
        Union(u, v);
        ++c;
    }

    if (c == n - 1)
        cout << res << '\n';
    else 
        cout << "IMPOSSIBLE\n";
}
