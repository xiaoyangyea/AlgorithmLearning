#include<vector>
#include<iostream>
using namespace std;
int main() {
    int t, m;
    cin>>t>>m;
    vector<int>c(m), w(m), v(t + 1, 0);
    for(int i = 0; i < m; i ++)
        cin>>c[i]>>w[i];
    for(int i = 0; i < m; i ++) {
        for(int j = t; j >= c[i]; j --)
            v[j] = max(v[j], v[j - c[i]] + w[i]);
    }
    int res = 0;
    for(int i = 0; i <= t; i ++)
        res = max(res, v[i]);
    cout<<res<<'\n';
}