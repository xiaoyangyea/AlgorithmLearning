//Unsolved.
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

void pushDown(int pos, int len, vector<int>& tree, vector<int>& add) {
    if(add[pos]) {
        tree[pos<<1] = add[pos] > 0 ? (len - (len >> 1)) : 0;
        add[pos<<1] = add[pos];
        tree[pos<<1|1] = add[pos] > 0 ? (len >> 1) : 0;
        add[pos<<1|1] = add[pos];
        add[pos] = 0;
    }
}

void update(int l, int r, int pos, int x, int y, int k, vector<int>& tree, vector<int>& add) {
    if(x <= l && r <= y) {
        tree[pos] = k ? (r - l + 1) : 0;
        add[pos] = k ? 1 : -1;
        return;
    }
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + ((r - l) >> 1);
    if(x <= mid) update(l, mid, pos<<1, x, y, k, tree, add);
    if(y > mid) update(mid+1, r, pos<<1|1, x, y, k, tree, add);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}
 
int query(int l, int r, int pos, int x, int y, vector<int>& tree, vector<int>& add) {
    if(x <= l && r <= y) return tree[pos];
    pushDown(pos, r - l + 1, tree, add);
    int mid = l + ((r - l) >> 1), sum = 0;
    if(x <= mid) sum += query(l, mid, pos<<1, x, y, tree, add);
    if(y > mid) sum += query(mid+1, r, pos<<1|1, x, y, tree, add);
    return sum;
}

int main() {

}