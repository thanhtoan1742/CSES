#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

struct Task {
    int duration;
    int deadline;

    bool operator<(const Task& other) const & {
        return duration < other.duration;
    }
};

int n;
Task a[maxN];

long long res;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i].duration >> a[i].deadline;
    sort(a, a + n);

    res = 0;
    long long current_time = 0;
    for (int i = 0; i < n; ++i) {
        current_time += a[i].duration;
        res += a[i].deadline - current_time;
    }

    cout << res << '\n';
}