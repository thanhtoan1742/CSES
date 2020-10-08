#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e3 + 100;
const int base = 1e9 + 7;

int n;
string a[maxN];

int f[maxN][maxN];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    f[0][0] = 1;
    for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) {
        if (a[i][j] == '*') {
            f[i][j] = 0;
            continue;
        }

        f[i + 1][j] = (f[i + 1][j] + f[i][j])%base;
        f[i][j + 1] = (f[i][j + 1] + f[i][j])%base;
    }    

    cout << f[n - 1][n - 1] << '\n';
}
