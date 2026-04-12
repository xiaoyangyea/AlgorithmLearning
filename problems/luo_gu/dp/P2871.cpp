#include<vector>
#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    vector<int>w(n), d(n), v(m + 1, 0);
    for(int i = 0; i < n; i ++) {
        cin>>w[i]>>d[i];
        for(int j = m; j >= w[i]; j --)
            v[j] = max(v[j], v[j - w[i]] + d[i]);
    }
    int res = 0;
    for(int i = 0; i <= m; i ++)
        res = max(res, v[i]);
    cout<<res<<'\n';
}