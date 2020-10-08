#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];

vector<int> f;

int res;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    res = 0;
    f.push_back(0);
    for (int i = 1; i <= n; ++i) 
        if (a[i] > f.back()) {
            ++res;
            f.push_back(a[i]);
        }
        else {
            auto it = lower_bound(f.begin(), f.end(), a[i]);
            *it = a[i];
        }

    cout << res << '\n';
}
