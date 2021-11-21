#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;


using Board = array<array<int, 3>, 3>;

int const dx[] = {0, 1};
int const dy[] = {1, 0};
ll p10[15];


void make_p10() {
    p10[0] = 1;
    for (int i = 1; i < 15; ++i)
        p10[i] = p10[i - 1]*10;
}


inline ll encode(Board const & b) {
    ll code = 0;
    ll p = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            code += p * b[i][j];
            p *= 10;
        }

    return code;
}

Board decode(ll code) {
    Board b;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            b[i][j] = code % 10;
            code /= 10;
        }
    return b;
}


ll make_goal() {
    Board b;
    b[0][0] = 1; b[0][1] = 2; b[0][2] = 3;
    b[1][0] = 4; b[1][1] = 5; b[1][2] = 6;
    b[2][0] = 7; b[2][1] = 8; b[2][2] = 9;
    return encode(b);
}

auto const goal = make_goal();

unordered_map<ll, int> cost;


inline bool inside(int x, int y) {
    return x > -1 && x < 3 && y > -1 && y < 3;
}

inline int idx(int x, int y) {
    return x*3 + y;
}


int solve(Board & b) {
    auto u = encode(b);
    if (u == goal)
        return 0;

    queue<Board> q;
    cost[u] = 0;
    q.push(b);
    while (!q.empty()) {
        auto b = q.front();
        q.pop();
        auto u = encode(b);
        // cerr << u << "\n";

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 2; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (!inside(x, y))
                        continue;

                    auto v = u;
                    v += (b[x][y] - b[i][j])*p10[idx(i, j)];
                    v += (b[i][j] - b[x][y])*p10[idx(x, y)];
                    swap(b[i][j], b[x][y]);
                    // cerr << "    " << v << "\n";


                    if (!cost.count(v)) {
                        cost[v] = cost[u] + 1;
                        if (v == goal)
                            return cost[v];
                        q.push(b);
                    }


                    swap(b[i][j], b[x][y]);
                }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    make_p10();

    Board b;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> b[i][j];
    cout << solve(b);

    return 0;
}
