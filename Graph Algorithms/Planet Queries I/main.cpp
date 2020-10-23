// This is perfectly ok

// #include <bits/stdc++.h>
 
// using namespace std;
// const int maxN = 2e5 + 100;
 
// #define sqr(a) ((a) * (a))
// #define minimize(a, b) a = min((a), (b))
// #define maximize(a, b) a = max((a), (b))
 
// int n, q;
// int a[maxN];
// int deg[maxN];
 
// int nb[maxN], e[maxN], il[maxN];
// int sp[maxN];
// vector<int> s;
 
// void dfs(int u) {
//     --deg[u];
//     e[u] = sp[u] = s.size();
//     s.push_back(u);
 
//     --deg[a[u]];
//     if (!deg[a[u]]) {
//         nb[a[u]] = nb[u];
//         dfs(a[u]);
//         e[u] = e[a[u]];
//     }
// }
 
// void make_lb(int u) {
//     if (nb[a[u]] < 0) make_lb(a[u]);
//     if (e[u] == sp[u]) nb[u] = sp[a[u]];
//     else nb[u] = nb[a[u]];
// }
 
// int jump(int x, int k) {
//     if (sp[x] + k <= e[x]) 
//         return s[sp[x] + k];
 
//     if (il[x] && nb[x] == sp[x]) {        
//         k %= e[x] - sp[x] + 1;
//         return jump(x, k);
//     }
 
//     k -= e[x] - sp[x] + 1;
//     x = s[nb[x]];
//     return jump(x, k);
// }
 
// int main(int argc, char* argv[]) {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
 
//     cin >> n >> q;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         ++deg[a[i]];
//         nb[i] = -1;
//     }
 
//     for (int i = 1; i <= n; ++i) 
//         if (!deg[i])
//             dfs(i);
 
//     for (int i = 1; i <= n; ++i)
//         if (deg[i] > 0) {
//             il[i] = 1;
//         }
        
//     for (int i = 1; i <= n; ++i) 
//         if (deg[i] > 0) {
//             deg[i] = 0;
//             nb[i] = s.size();
//             dfs(i);
//         }
 
//     for (int i = 1; i <= n; ++i) 
//         if (nb[i] < 0) 
//             make_lb(i);
 
 
//     while (q--) {
//         int x, k;
//         cin >> x >> k;
 
//         cout << jump(x, k) << '\n';
//     }
 
//     // for (int u: s)
//     //     cout << u << ' ';
//     // cout << '\n';
//     // for (int i = 1; i <= n; ++i)
//     //     cout << i << ' ' << il[i] << ' ' << sp[i] << ' ' << lb[i] << ' ' << e[i] << '\n';
// }


// SOL 2: LCA
// Much quicker interm of implementation time.

#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 2e5 + 100;
const int maxL = 31;
 
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))
 
int n, q;
int nex[maxN][maxL];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) 
        cin >> nex[i][0];

    for (int j = 1; j < maxL; ++j)
        for (int i = 1; i <= n; ++i)
            nex[i][j] = nex[nex[i][j - 1]][j - 1];

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = maxL - 1; i >= 0; --i)
            if (k >= 1 << i) {
                x = nex[x][i];
                k -= 1 << i;
            }

        cout << x << '\n';
    }
}
