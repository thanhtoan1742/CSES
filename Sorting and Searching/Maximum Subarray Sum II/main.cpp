#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, x, y;
long long a[maxN];

deque<int> q;

long long res;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x >> y;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], a[i] += a[i - 1];

    res = -1e18;
    for (int i = 1; i <= n; ++i) {
        if (i - x >= 0) {
            while (!q.empty() && a[q.back()] > a[i - x]) q.pop_back();
            q.push_back(i - x);
        }
        while (!q.empty() && q.front() < i - y) q.pop_front();
        if (!q.empty()) 
            maximize(res, a[i] - a[q.front()]);

        // if (!q.empty()) 
        //     cout << "i j: " << i << ' ' << q.front() << "\na[i] a[j]: " << a[i] << ' ' << a[q.front()] << '\n';
    }

    cout << res << '\n';
}
