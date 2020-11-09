// This one has better run time, also this is my original idea.
// But this one is more troublesome to implement.
#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 21;
const int base = 1e9 + 7;
 
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))
#define gb(a, n) (((a) >> (n))&1)
 
int fast_mod(const int& input, const int& ceil) {
    return input >= ceil ? input % ceil : input;
}
 
struct US {
    int u, s;
 
    US() {
    }
 
    US(int _u, int _s) 
    : u(_u), s(_s) {
    }
 
};
 
int n, m;
vector<int> adj[maxN];
 
queue<US> q;
unsigned long long f[maxN][1 << maxN];
unsigned long long res;
 
bool iq[maxN][1 << maxN];
 
void BFS() {
    f[0][1] = 1;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
 
        if (gb(u.s, n - 1)) 
            continue;
 
        for (int v: adj[u.u])
            if (!gb(u.s, v)) {
                int s = u.s | (1 << v);
                f[v][s] = fast_mod(f[v][s] + f[u.u][u.s], base);
 
                if (!iq[v][s]) {
                    q.emplace(v, s);
                    iq[v][s] = true;
                }
 
            }
    }
 
    res = f[n - 1][(1 << n) - 1] % base;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
    }   
 
    BFS();
 
    cout << res << '\n';
}
