#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 500 + 10;

int n, m;
int f[maxN][maxN];

int cal(int n, int m) {
    if (f[n][m] > 0)
        return f[n][m];
    if (n == m) {
        f[n][m] = 0;
        return 0;
    }

    f[n][m] = n*m;
    for (int i = 1; i < n; ++i)
        minimize(f[n][m], cal(i, m) + cal(n - i, m) + 1);
    for (int j = 1; j < m; ++j)
        minimize(f[n][m], cal(n, j) + cal(n, m - j) + 1);
    return f[n][m];
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        f[i][j] = -1;

    cout << cal(n, m) << '\n';
}
