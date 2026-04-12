#include<vector>
#include<iostream>
using namespace std;

static long long m;

void initTree(int l, int r, int pos, vector<long long>& tree) {
    if(l == r) {
        cin >> tree[pos];
        return;
    }
    int mid = l + ((r - l) >> 1);
    initTree(l, mid, pos<<1, tree);
    initTree(mid+1, r, pos<<1|1, tree);
    tree[pos] = tree[pos<<1] + tree[pos<<1|1];
}

void pushDown(int pos, long long len,vector<long long>& tree, vector<long long>& add, vector<long long>& mut) {
    if(mut[pos] != 1) {
        tree[pos<<1] = (tree[pos << 1] % m) * (mut[pos] % m) % m;
        tree[pos<<1|1] = (tree[pos << 1 | 1] % m) * (mut[pos] % m) % m;
        mut[pos<<1] = (mut[pos<<1] % m) * (mut[pos] % m) % m;
        mut[pos<<1|1] = (mut[pos<<1|1] % m) * (mut[pos] % m) % m;
        add[pos<<1] = (add[pos<<1] % m) * (mut[pos] % m) % m;
        add[pos<<1|1] = (add[pos<<1|1] % m) * (mut[pos] % m) % m;
        mut[pos] = 1;   //1 < k < 1e4
    }
    if(add[pos]) {
        tree[pos<<1] += (len - (len >> 1)) * 1ll * (add[pos] % m);
        tree[pos<<1] %= m;
        tree[pos<<1|1] += (len >> 1) * 1ll * (add[pos] % m) ;
        tree[pos<<1|1] %= m;
        add[pos<<1] += add[pos];
        add[pos<<1] %= m;
        add[pos<<1|1] += add[pos];
        add[pos<<1|1] %= m;
        add[pos] = 0;
    }
    tree[pos<<1] %= m;
    tree[pos<<1|1] %= m;
}

void updateAdd(int l, int r, int pos, int x, int y, long long k, vector<long long>& tree, vector<long long>& mut, vector<long long>& add) {
    // cout << "exe add: pos=" << pos << " l=" << l << " r=" << r 
    //  << " tree=" << tree[pos] 
    //  << " mut=" << mut[pos] 
    //  << " add=" << add[pos] << endl;
    if(x <= l && r <= y) {
        tree[pos] += (r - l + 1) * 1ll * k;
        tree[pos] %= m;
        add[pos] += k;
        add[pos] %= m;
        return;
    }
    pushDown(pos, r - l + 1, tree, add, mut);
    int mid = l + r >> 1;
    if(x <= mid)
        updateAdd(l, mid, pos<<1, x, y, k, tree, mut, add);
    if(y > mid)
        updateAdd(mid+1, r, pos<<1|1, x, y, k, tree, mut, add);
    tree[pos] = tree[pos<<1|1] + tree[pos<<1];
    tree[pos] %= m;
}

void updateMut(int l, int r, int pos, int x, int y, long long k, vector<long long>& tree, vector<long long>& mut, vector<long long>& add) {
    // cout << "exe mut: pos=" << pos << " l=" << l << " r=" << r 
    //  << " tree=" << tree[pos] 
    //  << " mut=" << mut[pos] 
    //  << " add=" << add[pos] << endl;
    if(x <= l && r <= y) {
        tree[pos] = (tree[pos] % m) * k % m;
        mut[pos] = (mut[pos] % m) * k % m;
        add[pos] = (add[pos] % m) * k % m;
        return;
    }
    pushDown(pos, r - l + 1, tree, add, mut);
    int mid = l + r >> 1;
    if(x <= mid)
        updateMut(l, mid, pos<<1, x, y, k, tree, mut, add);
    if(y > mid)
        updateMut(mid+1, r, pos<<1|1, x, y, k, tree, mut, add);
    tree[pos] = tree[pos<<1|1] + tree[pos<<1];
    tree[pos] %= m;
}

long long query(int l, int r, int pos, int x, int y, vector<long long>& tree, vector<long long>& mut, vector<long long>& add) {
    // cout << "exe qry: pos=" << pos << " l=" << l << " r=" << r 
    //  << " tree=" << tree[pos] 
    //  << " mut=" << mut[pos] 
    //  << " add=" << add[pos] << endl;
    if(x <= l && r <= y) return tree[pos];
    pushDown(pos, r - l + 1, tree, add, mut);
    int mid = l + r >> 1;
    long long sum = 0;
    if(x <= mid) sum += query(l, mid, pos<<1, x, y, tree, mut, add) % m;
    if(y > mid) sum += query(mid+1, r, pos<<1|1, x, y, tree, mut, add) % m;
    return sum % m;
}

void disp(int l, int r, int pos, vector<long long> tree, vector<long long> mut, vector<long long> add) {
    if(l == r) {
        cout<<tree[pos]<<' '<<mut[pos]<<' '<<add[pos]<<'\n';
        return;
    }
    int mid = l + r >> 1;
    disp(l, mid, pos<<1, tree, mut, add);
    disp(mid+1, r, pos<<1|1, tree, mut, add);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> tree(n << 2), mut(n << 2, 1), add(n << 2, 0);
    cin >> m;
    initTree(1, n, 1, tree);
    // disp(1, n, 1, tree, mut, add);
    // cout<<'\n';
    while(q --) {
        int o, x, y;
        long long k;
        cin>>o>>x>>y;
        if(o == 1) {
            cin>>k;
            updateMut(1, n, 1, x, y, k, tree, mut, add);
        }
        else if(o == 2) {
            cin>>k;
            updateAdd(1, n, 1, x, y, k, tree, mut, add);
        }
        else if(o == 3) {
            cout << query(1, n, 1, x, y, tree, mut, add) % m << '\n';
        }
        // disp(1, n, 1, tree, mut, add);
        // cout<<'\n';
    }
}

