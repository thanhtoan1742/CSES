#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 500 + 10;
const long long maxC = 1e9;

int n, m, q;
long long a[maxN][maxN];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) 
        if (i == j) a[i][j] = 0;
        else a[i][j] = n*maxC;
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        minimize(a[x][y], c);
        minimize(a[y][x], c);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            minimize(a[i][j], a[i][k] + a[k][j]);

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (a[x][y] == n*maxC) cout << "-1\n";
        else cout << a[x][y] << '\n';
    }
}
