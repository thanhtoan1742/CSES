#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, q;
long long a[maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] -  a[l - 1] << '\n';
    }
}