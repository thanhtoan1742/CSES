#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e3 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
int a[maxN][maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int q;
    cin >> n >> q;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[j - 1] == '*');
    }

    while (q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1] << '\n';
    }
}   