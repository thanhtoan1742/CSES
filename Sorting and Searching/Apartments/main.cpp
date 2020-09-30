#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, m, k;
int a[maxN], b[maxN];

int res;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    res = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && a[i] > b[j] + k)
            ++j;

        if (j < m && a[i] >= b[j] - k) {
            ++j;
            ++res;
        }
    }

    cout << res << '\n';
}