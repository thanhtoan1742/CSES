#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];

int res[maxN];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i]; 

    a[0] = -1000;
    for (int i = 1; i <= n; ++i) {
        res[i] = i - 1;
        while (a[res[i]] >= a[i]) res[i] = res[res[i]];
    }

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
    cout << '\n';
}
