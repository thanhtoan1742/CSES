#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
pair<int, bool> a[2*maxN];

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].first = x; a[i].second = 0;
        a[i + n].first = y; a[i + n].second = 1;
    }    
    sort(a, a + 2*n);

    int res = 0;
    int t = 0;
    for (int i = 0; i < n + n; ++i)  {
        t += a[i].second ? -1 : 1;
        maximize(res, t);
    }
        
    cout << res << '\n';
}