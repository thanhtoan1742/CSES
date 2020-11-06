#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

int n, m;
long long a[maxN];
vector<int> adj[maxN];

int numc;
int num[maxN], low[maxN];
bool deleted[maxN];
vector<int> st;

int rt[maxN];
vector<int> adj_cc[maxN];

long long f[maxN];

void DFS_CC(int u) {
    low[u] = num[u] = ++numc;
    st.push_back(u);

    
    for (int v: adj[u]) {
        if (deleted[v]) continue;

        if (!num[v]) {
            DFS_CC(v);
            minimize(low[u], low[v]);
        }
        else 
            minimize(low[u], num[v]);
    }


    if (low[u] >= num[u]) {
        // cout << u << '\n';
        while (true) {
            int v = st.back();
            st.pop_back();

            deleted[v] = true;
            rt[v] = u;
            for (int y: adj[v])
                adj_cc[rt[v]].push_back(y);

            if (v == u)
                break;
            else 
                a[u] += a[v];
        }
    }
}

void DFS_Cal(int u) {
    f[u] = a[u];

    for (int v: adj_cc[u]) {
        if (rt[v] == u) continue;

        if (!f[rt[v]]) 
            DFS_Cal(rt[v]);

        maximize(f[u], f[rt[v]] + a[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i)
        if (!num[i]) 
            DFS_CC(i);


    for (int i = 1; i <= n; ++i)
        if (rt[i] == i && !f[i]) 
            DFS_Cal(i);

    cout << *max_element(f + 1, f + 1 + n) << '\n';

    // for (int i = 1; i <= n; ++i)
    //     cout << i << ' ' << rt[i] << ' ' << a[i] << ' ' << f[i] << '\n';
}