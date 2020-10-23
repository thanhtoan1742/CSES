#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

int n;
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
    }
    else e[u] = sp[u];
}

void make_nb(int u) {
    int v = a[u];
    if (nb[v] < 0) make_nb(v);

    if (e[u] == sp[u]) nb[u] = sp[v];
    else nb[u] = nb[v];
}

int get_k(int u) {
    if (nb[u] <= sp[u] && sp[u] <= e[u])
        return e[u] - nb[u] + 1;

    int k = e[u] - sp[u] + 1;
    u = s[nb[u]];
    return k + get_k(u);
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++deg[a[i]];
        nb[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
        if (!deg[i])    
            dfs(i);

    for (int i = 0; i <= n; ++i)
        if (deg[i] > 0) {
            int u = i;
            nb[u] = s.size();
            do 
            {
                deg[u] = -1;
                sp[u] = s.size();
                s.push_back(u);
                nb[a[u]] = nb[u];
                u = a[u];
            }
            while (u != i);
            
            for (int j = sp[i]; j < s.size(); ++j) 
                e[s[j]] = s.size();
        }
    for (int i = 1; i <= n; ++i)
        if (nb[i] < 0) make_nb(i);

    for (int i = 1; i <= n; ++i)
        cout << get_k(i) - 1 << ' ';
    cout << '\n';
}
