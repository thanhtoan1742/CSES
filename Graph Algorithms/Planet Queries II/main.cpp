#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

int n, q;
int a[maxN];
int deg[maxN];

int e[maxN], nb[maxN], sp[maxN];
vector<int> s;

void dfs(int u) {
    --deg[u];
    sp[u] = s.size();
    s.push_back(u);

    int v = a[u];
    --deg[v];
    if (!deg[v]) {
        dfs(v);
        e[u] = e[v];
        nb[v] = nb[u];
    }
    else 
        e[u] = sp[u];
}

void make_nb(int u) {
    int v = a[u];
    if (nb[v] < 0) make_nb(v);

    if (e[u] == sp[u]) nb[u] = sp[v];
    else nb[u] = nb[v];
}

int get_k(int x, int y) {
    if (sp[x] <= sp[y] && sp[y] <= e[x]) {
        int k = sp[y] - sp[x];
        return k;
    }

    if (nb[x] <= sp[x] && sp[x] <= e[x] && sp[x] == nb[x]) 
        return -1;

    int k = e[x] - sp[x] + 1;
    x = s[nb[x]];
    int t = get_k(x, y);
    return (t < 0) ? -1 : k + t;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++deg[a[i]];
        nb[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
        if (!deg[i]) 
            dfs(i);

    for (int i = 1; i <= n; ++i)
        if (deg[i] > 0) {
            deg[i] = 0;
            nb[i] = s.size();
            dfs(i);
        }

    for (int i = 1; i <= n; ++i)
        if (nb[i] < 0) 
            make_nb(i);

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << get_k(x, y) << '\n';
    }
}
