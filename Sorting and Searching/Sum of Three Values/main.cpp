#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

template<typename T>
void log(T* begin, T* end) {
    for (auto it = begin; it != end; ++it)
        cout << *it << ' ';
    cout << '\n';
}

const int maxN = 5000 + 100;

struct Value {
    int i;
    long long u;

    bool operator < (const Value& other) const & {
        return u < other.u;
    }

    operator int() const & {
        return u;
    }
};

int n;
long long x;
Value a[maxN];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; ++i){
        cin >> a[i].u;
        a[i].i = i + 1;
    }
    sort(a, a + n);

    for (int i = 0; i < n; ++i){
        int k = n - 1;
        for (int j = i + 1; j < n; ++j) {
            while (k > j && a[i] + a[j] + a[k] > x) --k;
            if (k <= j) break;

            if (a[i] + a[j] + a[k] == x) {
                cout << a[i].i << ' ' << a[j].i << ' ' << a[k].i << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}