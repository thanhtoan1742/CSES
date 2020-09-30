#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int n;
long long a[25];

long long curr;
long long res;

void divide(int i) {
    if (i == n) {
        res = min(res, abs(curr));
        return;
    }

    curr += a[i];
    divide(i + 1);
    curr -= 2*a[i];
    divide(i + 1);
    curr += a[i];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    res = 1e15; 
    curr = 0;
    divide(0);

    cout << res << '\n';
}