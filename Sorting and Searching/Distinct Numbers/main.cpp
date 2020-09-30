#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];

int res;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    res = 1;
    for (int i = 1; i < n; ++i)
        res += a[i] != a[i - 1];

    cout << res << '\n';
}