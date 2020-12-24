#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    array<array<double, 8>, 8> a, b, f;
    for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
        f[i][j] = 1;

    int n;
    cin >> n;

    for (int x = 0; x < 8; ++x)
    for (int y = 0; y < 8; ++y) {
        for (int i = 0; i < 8; ++i)
            fill(a[i].begin(), a[i].end(), 0);
        a[x][y] = 1;

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < 8; ++i)
                fill(b[i].begin(), b[i].end(), 0);
            
            for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j) {
                double m = (i > 0) + (j > 0) + (i < 7) + (j < 7);
                
                if (i)
                    b[i - 1][j] += a[i][j]/m;
                if (j)
                    b[i][j - 1] += a[i][j]/m;
                if (i < 7)
                    b[i + 1][j] += a[i][j]/m;
                if (j < 7)
                    b[i][j + 1] += a[i][j]/m;
            }
            swap(a, b);
        }

        for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            f[i][j] *= 1 - a[i][j];
    }

    double res = 0;
    for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) 
        res += f[i][j];
    cout << fixed << setprecision(6) << res << '\n';
}
