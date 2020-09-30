#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

typedef pair<int, int> ii;
#define F first
#define S second

int n;
ii a[maxN];

int f[maxN];

bool cmp(const ii& a, const ii& b) {
    return a.S < b.S;
}

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].F >> a[i].S;
    sort(a, a + n, cmp);

    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        ii x(0, a[i].F);

        int j = upper_bound(a, a + n, x, cmp) - a - 1;
        if (j >= 0)
            f[i] = f[j] + 1;

        if (i > 0)
            f[i] = max(f[i], f[i - 1]);
    }

    cout << f[n - 1] << '\n';
}