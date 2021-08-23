#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

struct Node {
    char c;
    Node *l, *r;
    int sz;

    Node(char _c, int _sz = 0, Node *_l = nullptr, Node *_r = nullptr)
    : c(_c), sz(_sz), l(_l), r(_r) {
    }

    int size() {
        return sz;
    }

    void update() {
        sz = 1;
        if (l)
            sz += l->size();
        if (r)
            sz += r->size();
    }
};

struct Tree {
    Node* root;

    void build(const string &s, int i, int sz) {
        if (sz == 0)
            return;
    }

    Tree(const string &s) {
        build(s, 0, s.size());
    }

    pair<Node*, Node*> split(int i, int sz, Node *u = root) {
        if (!u)
            return {nullptr, nullptr};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}
