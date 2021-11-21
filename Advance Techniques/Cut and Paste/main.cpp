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
    char value;
    int sz;
    Node* left;
    Node* right;


    Node(char _value, int _sz = 0, Node *_left = nullptr, Node *_right = nullptr)
    : value(_value), sz(_sz), left(_left), right(_right) {
    }

    int size() {
        return sz;
    }

    void update() {
        sz = 1;
        if (left)
            sz += left->size();
        if (right)
            sz += right->size();
    }
};


struct Treap {
    Node* root;

    Treap(string const& a) {
        build_treap(a);
    }

    void build_treap(string const& a) {
        
    }

}




int n;
string a;






int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> n >> m;
    cin >> a;

    auto treap = build_treap();

    while (m--) {
        int x, y;
        cin >> x >> y;
        int k = y - x + 1;

        auto [left, temp] = split_treap(treap);
        auto [mid, right] = split_treap(temp);
        temp = merge_treap(left, right);
        treap = merge_treap(temp, mid);
    }
}
