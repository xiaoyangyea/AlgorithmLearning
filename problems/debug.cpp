#include<vector>
#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<long long> a, b;
    while(true) {
        int _a;
        cin>>_a;
        if(_a == 0) break;
        a.push_back(_a);
    }
    while(true) {
        int _b;
        cin>>_b;
        if(_b == 0) break;
        b.push_back(_b);
    }
    cout<<a.size()<<' '<<b.size()<<'\n';
    cout<<"index expect_output received_output\n";
    int cnt = 0;
    for(int i = 0; i < a.size(); i ++)
        if(a[i] != b[i]) cout<<i<<' '<<a[i]<<' '<<b[i]<<'\n', ++cnt;
    cout<<"covered: "<<a.size() - cnt<<", uncovered: "<<cnt<<'\n';
}