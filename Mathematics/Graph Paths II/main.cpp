#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 120;
const ll maxD = 2e18;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

struct matrix {
    ll d[maxN][maxN];

    matrix() {
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = maxD;
    }
 
    ll* operator[](int index) {
        return d[index];
    }
 
    matrix operator*(matrix& other) {
        matrix res;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] = min(res[i][j], d[i][k] + other[k][j]);
 
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

    int m, k;
    cin >> n >> m >> k;
    matrix a;
    while (m--) {
        int x, y;
        ll we;
        cin >> x >> y >> we;
        x--, y--;
        a[x][y] = min(a[x][y], we);
    }

    a = Pow(a, k);
    if (a[0][n - 1] == maxD)
        cout << "-1\n";
    else 
        cout << a[0][n - 1] << '\n';
}
