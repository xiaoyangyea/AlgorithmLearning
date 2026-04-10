#include<vector>
#include<iostream>
using namespace std;
typedef pair<int, int> PII;
int findRoot(int x, vector<PII>& root) {
    if(x != root[x].first)
        root[x].first = findRoot(root[x].first, root);
    return root[x].first;
}
void unionSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    if(_x == _y) return;
    if(root[_x].second < root[_y].second) root[_x].first = _y;
    else if(root[_x].second > root[_y].second) root[_y].first = _x;
    else {
        root[_y].first = _x;
        root[_x].second ++;
    }
}
bool isSameSet(int x, int y, vector<PII>& root) {
    int _x = findRoot(x, root);
    int _y = findRoot(y, root);
    return _x == _y;
}
void initSet(vector<PII>& root) {
    for(int i = 0; i < root.size(); i ++)
        root[i] = {i, 0};
}
struct Hollow
{
    int id;
    long long x, y, z;
    Hollow(int id = 0, long long x = 0, long long y = 0, long long z = 0) {
        this->id = id;
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
bool isConnected(Hollow h1, Hollow h2, long long r) {
    // cout<<h1.id<<' '<<h2.id<<' '<<r * r << ' ' << (h1.x - h2.x) * (h1.x - h2.x) + (h1.y - h2.y) * (h1.y - h2.y) + (h1.z - h2.z) * (h1.z - h2.z)<<'\n';
    return 4 * r * r >= (h1.x - h2.x) * (h1.x - h2.x) + (h1.y - h2.y) * (h1.y - h2.y) + (h1.z - h2.z) * (h1.z - h2.z);
}

void display(const vector<int>& arr) {
    for(int i = 0; i < arr.size(); i ++)
        cout<<arr[i]<<(i < arr.size() - 1 ? ' ':'\n');
}
int main() {
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        long long height, r;
        bool flag = true;
        cin>>height>>r;
        vector<Hollow>h(n + 1);
        vector<PII>root(n+1);
        vector<int>buttom, top;
        initSet(root);
        for(int i = 1; i <= n; i ++) {
            long long x, y, z;
            cin>>x>>y>>z;
            h[i] = Hollow(i, x, y, z);
            if(z <= r) buttom.push_back(i);
            if(z + r >= height) top.push_back(i);
        }
        // display(top);
        // display(buttom);
        for(int i = 1; i < n; i ++)
            for(int j = i + 1; j <= n; j ++) {
                if(isConnected(h[i], h[j], r))
                    unionSet(i, j, root); 
            }
        for(int i = 0; i < top.size(); i ++) {
            for(int j = 0; j < buttom.size(); j ++)
                if(isSameSet(top[i], buttom[j], root)) {
                    cout<<"Yes\n";
                    flag = false;
                    break;
                }
            if(!flag) break;
        }
        if(flag) cout<<"No\n";
    }  
}