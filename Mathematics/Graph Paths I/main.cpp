#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const ll M = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct matrix {
    int n;
    ll d[120][120];

    matrix(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = 0;
    }
 
    ll* operator[](int index) {
        return d[index];
    }
 
    matrix operator*(matrix& other) {
        matrix res(n);
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < n; ++k)
                res[i][j] = (res[i][j] + d[i][k]*other[k][j]) % M;
        }
 
        return res;
    }
};

matrix Pow(matrix a, ll n) {
    if (n == 1)
        return a;
 
    auto t = Pow(a, n/2);
    t = t*t;
    if (n&1)
        t = t*a;
 
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    matrix a(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y]++;
        // a[y][x] = 1;
    }

    a = Pow(a, k);

    cout << a[0][n - 1] << '\n';
}
