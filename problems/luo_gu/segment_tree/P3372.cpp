#include<vector>
#include<iostream>
using namespace std;
void initTree(int l, int r, int pos, vector<long long>& tree) {
    if(l == r) {
        cin>>tree[pos];
        return;
    }
    int mid = l + r >> 1;
    initTree(l, mid, pos<<1, tree);
    initTree(mid+1, r, pos<<1|1, tree);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

void pushDown(int pos, int len, vector<long long>& tree, vector<long long>& add) {
    if(add[pos]) {
        tree[pos<<1] += (len - (len >> 1)) * add[pos];
        tree[pos<<1|1] += (len >> 1) * add[pos];
        add[pos<<1] += add[pos];
        add[pos<<1|1] += add[pos];
        add[pos] = 0;
    }
}

void update(int l, int r, int pos, int x, int y, long long k, vector<long long>& tree, vector<long long>& add) {
    if(x <= l && r <= y) {
        tree[pos] += (r - l + 1) * k;
        add[pos] += k;
        return;
    }
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + r >> 1;
    if(x <= mid)
        update(l, mid, pos<<1, x, y, k, tree, add);
    if(y > mid)
        update(mid+1, r, pos<<1|1, x, y, k, tree, add);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

long long query(int l, int r, int pos, int x, int y, vector<long long>& tree, vector<long long>& add) {
    if(x <= l && r <= y) return tree[pos];
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + r >> 1;
    long long sum = 0;
    if(x <= mid) 
        sum += query(l, mid, pos<<1, x, y, tree, add);
    if(y > mid)
        sum += query(mid+1, r, pos<<1|1, x, y, tree, add);
    return sum;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<long long>tree(n << 2), add(n << 2, 0);
    initTree(1, n, 1, tree);
    while(m --) {
        int o, x, y;
        long long k;
        cin>>o>>x>>y;
        if(o == 1) {
            cin>>k;
            update(1, n, 1, x, y, k, tree, add);
        }
        else {
            cout<<query(1, n, 1, x, y, tree, add)<<'\n';
        }
    }
}