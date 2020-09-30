#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
long long a[maxN];

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a[0] = 0;
    long long t = a[0];
    long long res = -2e9;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        res = max(res, a[i] - t);
        t = min(a[i], t);
    }
    cout << res << '\n';
}