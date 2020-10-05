#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

struct Movie {
    int beg, end, idx;

    bool operator<(const Movie& other) const & {
        if (end != other.end)
            return end < other.end;
        else 
            if (beg != other.beg)
                return beg < other.beg;
            else
                return idx < other.idx;
    }
};

int n, k; 
Movie a[maxN];

set<Movie> s;
int res;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].beg >> a[i].end;
        a[i].idx = i;
    }   
    sort(a, a + n);

    res = 0;
    for (int i = 0; i < n; ++i) {
        Movie t;
        t.end = a[i].beg;

        auto it = s.upper_bound(t);
        if (it != s.begin()) {
            --it;
            s.erase(it);

            ++res;
            s.insert(a[i]);
        }
        else if (s.size() < k) {
            ++res;
            s.insert(a[i]);
        }
    }

    cout << res << '\n';

}
