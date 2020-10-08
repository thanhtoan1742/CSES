#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 5e3 + 100;
const long long maxF = 1e18;

int n;
long long a[maxN];

long long f[maxN][maxN][2];

void print_f(int i, int j) {
    cout << i << ' ' << j << ": " << f[i][j][0] << ' ' << f[i][j][1] << '\n';
}

long long dp() {
    for (int i = n; i; --i) {
        f[i][i][0] = a[i];
        f[i][i][1] = 0;

        for (int j = i + 1; j <= n; ++j) 
            if (f[i + 1][j][1] + a[i] > f[i][j - 1][1] + a[j]) {
                f[i][j][0] = f[i + 1][j][1] + a[i];
                f[i][j][1] = f[i + 1][j][0];
            }
            else {
                f[i][j][0] = f[i][j - 1][1] + a[j];
                f[i][j][1] = f[i][j - 1][0];
            }
    }
    return f[1][n][0];
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a[0] = a[n + 1] = -1e18;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    cout << dp() << '\n';
}
