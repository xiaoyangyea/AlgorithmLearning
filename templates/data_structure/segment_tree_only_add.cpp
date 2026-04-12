#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;

void initTree(int l, int r, int pos, vector<ll>& tree, vector<int>arr) {
    if(l == r) {
        tree[pos] = arr[l];
        return;
    }
    int mid = l + (r - l >> 1);
    initTree(l, mid, pos<<1, tree, arr);
    initTree(mid+1, r, pos<<1|1, tree, arr);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

void pushDown(int pos, int len, vector<ll>&tree, vector<ll>&add) {
    if(add[pos]) {
        add[pos<<1] += add[pos];
        add[pos<<1|1] += add[pos];
        tree[pos<<1] += add[pos] * (len - (len >> 1));
        tree[pos<<1|1] += add[pos] * (len >> 1);
        add[pos] = 0;
    }
}

void update(int l, int r, int pos, int x, int y, int k, vector<ll>& tree, vector<ll>& add) {
    if(x <= l && r <= y) {
        add[pos] += k;
        tree[pos] += k * (r - l + 1);
        return;
    }
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + (r - l >> 1);
    if(x <= mid)
        update(l, mid, pos<<1, x, y, k, tree, add);
    if(y > mid)
        update(mid+1, r, pos<<1|1, x, y, k, tree, add);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

long long query(int l, int r, int pos, int x, int y, vector<ll>& tree, vector<ll>& add) {
    if(x <= l && r <= y) return tree[pos];
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + (r - l >> 1);
    long long sum = 0;
    if(x <= mid)
        sum += query(l, mid, pos<<1, x, y, tree, add);
    if(y > mid)
        sum += query(mid+1, r, pos<<1|1, x, y, tree, add);
    return sum;
}