#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

struct Customer {
    int begin, end, id;

    bool operator<(const Customer& other) const & {
        return begin < other.begin;
    }
};

struct Room {
    int end, id;

    Room(int _end, int _id)
    : end(_end), id(_id) {
    }

    bool operator<(const Room& other) const & {
        return end > other.end;
    }
};

int n;
Customer a[maxN];

priority_queue<Room> q;
int ro[maxN];

bool check(int m) {
    while (!q.empty())
        q.pop();
    for (int i = 0; i < m; ++i)
        q.emplace(0, i + 1);

    for (int i = 0; i < n; ++i) {
        if (a[i].begin <= q.top().end)
            return false;

        int id = q.top().id;
        q.pop();
        q.emplace(a[i].end, id);
        ro[a[i].id] = id;
    }
    return true;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].begin >> a[i].end;
        a[i].id = i;
    }
    sort(a, a + n);

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (!check(m))
            l = m + 1;
        else
            r = m;
    }

    check(r);
    cout << r << '\n';
    for (int i = 0; i < n; ++i)
        cout << ro[i] << ' ';
    cout << '\n';
}