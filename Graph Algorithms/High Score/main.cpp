#include <bits/stdc++.h>

using namespace std;
const int maxN = 2500 + 100;
const int maxM = 5000 + 100;
const long long maxD = 1e16;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

int n, m;
array<int, 3> e[maxM];

bool reachable[2][maxN];

long long d[maxN];
long long res;

void make_reachable() {
    reachable[0][1] = 1;
    reachable[1][n] = 1;
    for (int rep = 0; rep < n; ++rep)
        for (int i = 0; i < m; ++i) {
            reachable[0][e[i][1]] |= reachable[0][e[i][0]];
            reachable[1][e[i][0]] |= reachable[1][e[i][1]];
        }
        
}

void ford_bellman() {
    d[1] = 0;
    for (int i = 2; i <= n; ++i)
        d[i] = -maxD;

    for (int rep = 0; rep < n; ++rep) 
        for (int i = 0; i < m; ++i)
            maximize(d[e[i][1]], d[e[i][0]] + e[i][2]);

    res = d[n];
    for (int i = 0; i < m; ++i) 
        if (d[e[i][1]] < d[e[i][0]] + e[i][2] && reachable[1][e[i][0]] && reachable[0][e[i][0]]) {
            res = -1;
            return;
        }

}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
        cin >> e[i][0] >> e[i][1] >> e[i][2];

    make_reachable();
    ford_bellman();

    cout << res << '\n';
}
