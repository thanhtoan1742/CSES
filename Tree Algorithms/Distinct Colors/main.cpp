#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
int a[maxN];
vector<int> adj[maxN];

vector<int> s;
int sb[maxN], se[maxN];

map<int, int> ipre;
int nex[maxN];
vector<array<int, 2>> q[maxN];

int fen[maxN];

int res[maxN];

void DFS(int u = 1, int p = 0) {
    sb[u] = s.size() + 1;
    s.push_back(u);

    for (int v: adj[u]) {
        if (v == p)
            continue;

        DFS(v, u);
    }

    se[u] = s.size();
}

void add_fenwick(int u, int val) {
    for (; u <= n; u += u & -u)
        fen[u] += val;
}

int get_fenwick(int u) {
    int res = 0;
    for (; u; u &= u - 1)
        res += fen[u];

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS();

    // for (int i = 1; i <= n; ++i)
    //     cout << i << ' ' << sb[i] << ' '  << se[i] << '\n';

    for (int i = 1; i <= n; ++i)
        q[sb[i]].push_back({se[i], i});

    for (int i = 1; i <= n; ++i) {            
        int c = a[s[i - 1]];
        auto it = ipre.find(c);
        if (it == ipre.end()) 
            add_fenwick(i, 1);
        else 
            nex[it->second] = i;

        ipre[c] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (auto u: q[i])  
            res[u[1]] = get_fenwick(u[0]) - get_fenwick(i - 1);
        
        add_fenwick(i, -1);
        if (nex[i])
            add_fenwick(nex[i], 1);
    }

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}
