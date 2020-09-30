#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];

long long cal(int p) {
    long long res = 0;
    for (int i = 0; i < n; ++i) 
        res += abs(a[i] - p);
    return res;
}

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 0, r = 2e9;
    while (l < r) {
        int m = (l + r) / 2;
        
        long long x = cal(m);
        long long y = cal(m + 1);
        if (x < y)
            r = m;
        else 
            l = m + 1;
    }   

    cout << cal(r) << '\n';
}