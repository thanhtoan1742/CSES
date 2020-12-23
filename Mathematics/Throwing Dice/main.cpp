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
    static const int n = 6;
    ll d[n][n];

    ll* operator[](int index) {
        return d[index];
    }

    matrix operator*(matrix& other) {
        matrix res;
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < n; ++k)
                res[i][j] = (res[i][j] + d[i][k]*other[k][j]) % M;
        }

        return res;
    }

    void make_base() {
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = 0;

        for (int i = 0; i < n; ++i)
            d[0][i] = 1;

        for (int i = 1; i < n; ++i)
            d[i][i - 1] = 1;
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

    ll res[] = {1, 1, 2, 4, 8, 16, 32};
    
    ll n;
    cin >> n;
    if (n <= 6) {
        cout << res[n] << '\n';
        return 0;
    }
        

    matrix m;
    m.make_base();
    m = Pow(m, n - 6);

    ll s = 0;
    for (int i = 1; i <= 6; ++i)
        s = (s + res[i]*m[0][matrix::n - i]) % M;
    cout << s << '\n';
}
