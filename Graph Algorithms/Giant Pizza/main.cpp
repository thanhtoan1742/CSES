#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))
#define time_begin_measure  auto time_start = chrono::high_resolution_clock::now()
#define time_end_measure    auto time_stop = chrono::high_resolution_clock::now(); auto time_duration = chrono::duration_cast<chrono::milliseconds>(time_stop - time_start); cerr << time_duration.count() << "ms\n"

struct US {
    int u;
    bool s;

    US(int _u, bool _s) 
    : u(_u), s(_s) {
    }
};  


int n, m;
vector<US> adj[maxN][2];

vector<int> vis_v;
int st[maxN];

bool DFS(int u, bool s) {
    vis_v.push_back(u);

    for (auto v: adj[u][s])
        if (st[v.u] != -1) {
            if (st[v.u] != v.s) 
                return false;
        }
        else {
            st[v.u] = v.s;
            if (!DFS(v.u, !st[v.u])) 
                return false;
        }

    return true;
}

bool valid(int u, int s) {
    st[u] = s;
    vis_v.clear();
    bool res = DFS(u, !st[u]);

    if (!res) {
        while (!vis_v.empty()) {
            st[vis_v.back()] = -1;
            vis_v.pop_back();
        }
        return false;
    }
    else 
        return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        char sx, sy;
        int u, v;
        bool su, sv;
        cin >> sx >> u >> sy >> v;
        su = sx == '+';
        sv = sy == '+';

        adj[u][su].emplace_back(v, sv);
        adj[v][sv].emplace_back(u, su);
    }

    for (int i = 1; i <= n; ++i)
        st[i] = -1;
    for (int u = 1; u <= n; ++u) 
        if (st[u] == -1) {
            if (valid(u, 0)) continue;
            if (valid(u, 1)) continue;

            cout << "IMPOSSIBLE\n";
            return 0;
        }
    

    for (int i = 1; i <= n; ++i)
        cout << (st[i]? '+': '-');
    cout << '\n';
}