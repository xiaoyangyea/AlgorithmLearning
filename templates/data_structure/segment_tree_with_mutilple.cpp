#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
ll m;
void initTree(int l, int r, int pos, vector<ll>& tree, vector<ll>& arr) {
    if(l == r) {
        tree[pos] = arr[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    initTree(l, mid, pos<<1, tree, arr);
    initTree(mid+1, r, pos<<1|1, tree, arr);
    tree[pos] = (tree[pos<<1] + tree[pos<<1|1]) % m;
}
void pushDown(int pos, int len, vector<ll>& tree, vector<ll>& mut, vector<ll>& add) {
    if(mut[pos] != 1) {
        long long _mut = mut[pos] % m;

        tree[pos<<1] = (tree[pos<<1] % m) * _mut % m;
        mut[pos<<1] = (mut[pos<<1] % m) * _mut % m;
        add[pos<<1] = (add[pos<<1] % m) * _mut % m;

        tree[pos<<1|1] = (tree[pos<<1|1] % m) * _mut % m;
        mut[pos<<1|1] = (mut[pos<<1|1] % m) * _mut % m;
        add[pos<<1|1] = (add[pos<<1|1] % m) * _mut % m;

        mut[pos] = 1;
    }
    if(add[pos]) {
        long long _add = add[pos] % m;

        tree[pos<<1] = ((tree[pos<<1] % m) + _add % m * 1ll * (len - (len >> 1))) % m;
        add[pos<<1] = ((add[pos<<1] % m) + _add) % m;

        tree[pos<<1|1] = ((tree[pos<<1|1] % m) + _add % m * 1ll * (len >> 1)) % m;
        add[pos<<1|1] = ((add[pos<<1|1] % m) + _add) % m;

        add[pos] = 0;
    }
}

void updateAdd(int l, int r, int pos, int x, int y, ll k, vector<ll>& tree, vector<ll>& mut, vector<ll>& add) {
    if(x <= l && r <= y) {
        tree[pos] = ((tree[pos] % m) + (r - l + 1) * 1ll * k) % m;
        add[pos] = ((add[pos] % m) + k) % m;
        return;
    }
    pushDown(pos, r - l + 1, tree, mut, add);
    int mid = l + ((r - l) >> 1);
    if(x <= mid)
        updateAdd(l, mid, pos<<1, x, y, k, tree, mut, add);
    if(y > mid)
        updateAdd(mid+1, r, pos<<1|1, x, y, k, tree, mut, add);
    tree[pos] = (tree[pos<<1] + tree[pos<<1|1]) % m;
}

void updateMut(int l, int r, int pos, int x, int y, ll k, vector<ll>& tree, vector<ll>& mut, vector<ll>& add) {
    if(x <= l && r <= y) {
        tree[pos] = ((tree[pos] % m) * (k % m)) % m;
        mut[pos] = ((mut[pos] % m) * (k % m)) % m;
        add[pos] = ((add[pos] % m) * (k % m)) % m;
        return;
    }
    pushDown(pos, r - l + 1, tree, mut, add);
    int mid = l + ((r - l) >> 1);
    if(x <= mid)
        updateMut(l, mid, pos<<1, x, y, k, tree, mut, add);
    if(y > mid)
        updateMut(mid+1, r, pos<<1|1, x, y, k, tree, mut, add);
    tree[pos] = (tree[pos<<1] + tree[pos<<1|1]) % m;
}

ll query(int l, int r, int pos, int x, int y, vector<ll>& tree, vector<ll>& mut, vector<ll>& add) {
    if(x <= l && r <= y) return tree[pos] % m;
    pushDown(pos, r - l + 1, tree, mut, add);
    int mid = l + ((r - l) >> 1);
    ll sum = 0;
    if(x <= mid)
        sum += query(l, mid, pos<<1, x, y, tree, mut, add);
    if(y > mid)
        sum += query(mid+1, r, pos<<1|1, x, y, tree, mut, add);
    tree[pos] = (tree[pos<<1] + tree[pos<<1|1]) % m;
    return sum % m;
}

int main() {
    int n, q;
    cin>>n>>q>>m;
    vector<ll> tree((n << 2) + 5), add((n << 2) + 5, 0), mut((n << 2) + 5, 1), arr(n + 1);
    for(int i = 1; i <= n; i ++) cin>>arr[i];
    initTree(1, n, 1, tree, arr);
    while(q --) {
        int o, x, y;
        long long k;
        cin>>o>>x>>y;
        if(o == 3) {
            cout<<query(1, n, 1, x, y, tree, mut, add)<<'\n';
        }
        else {
            cin>>k;
            if(o == 1)
                updateMut(1, n, 1, x, y, k, tree, mut, add);
            else    
                updateAdd(1, n, 1, x, y, k, tree, mut, add);
        }
    }
}