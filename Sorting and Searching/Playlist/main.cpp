#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int n, m;
map<int, int> la;

int res;

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    m = 0;
    res = 0;
    int l = -1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        auto it = la.find(a);

        if (it != la.end())
            maximize(l, it->second);

        la[a] = i;
        maximize(res, i - l);
    }

    cout << res << '\n';
}