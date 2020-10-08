#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;
const int maxM = 100 + 10;
const unsigned int base = 1e9 + 7;

int n, m;
int a[maxN];

unsigned int f[maxN][maxM];

unsigned int res;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    if (a[0] == 0)
        for (int j = 1; j <= m; ++j) f[0][j] = 1;
    else 
        f[0][a[0]] = 1;

    for (int i = 1; i < n; ++i)
        if (a[i] == 0)
            for (int j = 1; j <= m; ++j)     
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + f[i - 1][j + 1]) % base;
        else 
            f[i][a[i]] = (f[i - 1][a[i]] + f[i - 1][a[i] - 1] + f[i - 1][a[i] + 1]) % base;

    res = 0;
    for (int j = 1; j <= m; ++j) 
        res = (res + f[n - 1][j]) % base;

    cout << res << '\n';
}
