#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 100 + 10;
const int maxA = 1e3 + 10;

int n;
int a[maxN];
bool f[maxN*maxA];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    f[0] = 1;
    
    int m = n*maxA;
    for (int i = 0; i < n; ++i)
        for (int j = m - 1; j >= 0; --j) 
            if (f[j] && j + a[i] < m) f[j + a[i]] = 1;

    int c = 0;
    for (int i = 1; i < m; ++i) c += f[i];

    cout << c << '\n';
    for (int i = 1; i < m; ++i)
        if (f[i]) cout << i << ' ';
    cout << '\n';
}
