#include<vector>
#include<iostream>
using namespace std;
void initTree(int l, int r, int pos, vector<int>& tree) {
    if(l == r) {
        tree[pos] = 1;
        return;
    }
    int mid = l + ((r - l) >> 1);
    initTree(l, mid, pos<<1, tree);
    initTree(mid+1, r, pos<<1|1, tree);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

void pushDown(int pos, vector<int>& tree, vector<int>& add) {
    if(add[pos] < 0) {
        tree[pos<<1] = 0;
        add[pos<<1] = -1;
        tree[pos<<1|1] = 0;
        add[pos<<1|1] = -1;
        add[pos] = 0;
    }
}

void update(int l, int r, int pos, int x, int y, vector<int>& tree, vector<int>& add) {
    if(x <= l && r <= y) {
        tree[pos] = 0;
        add[pos] = -1;
        return;
    }
    pushDown(pos, tree, add);
    int mid = l + ((r - l) >> 1);
    if(x <= mid)
        update(l, mid, pos<<1, x, y, tree, add);
    if(y > mid)
        update(mid+1, r, pos<<1|1, x, y, tree, add);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

int query(int l, int r, int pos, int x, int y, vector<int>& tree, vector<int>& add) {
    if(x <= l && r <= y) return tree[pos];
    int mid = l + ((r - l) >> 1), sum = 0;
    if(x <= mid) sum += query(l, mid, pos<<1, x, y, tree, add);
    if(y > mid) sum += query(mid+1, r, pos<<1|1, x, y, tree, add);
    return sum;
}

int main() {
    int l, m;
    cin>>l>>m;
    l ++;
    vector<int>tree(l<<2), add(l<<2, 0);
    initTree(1, l, 1, tree);
    while(m --) {
        int u, v;
        cin>>u>>v;
        update(1, l, 1, u + 1, v + 1, tree, add);
    }
    cout<<query(1, l, 1, 1, l, tree, add);
}