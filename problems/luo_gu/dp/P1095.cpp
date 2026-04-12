//upsolved
#include<vector>
#include<iostream>
using namespace std;
int main() {
    int m, s, t;
    cin>>m>>s>>t;
    int d1 = 0, d2 = 0;
    for(int i = 1; i <= t; i ++) {
        if(m >= 10) {
            d1 += 60;
            m -= 10;
        }
        else m += 4;
        d2 += 17;
        if(d1 > d2) d2 = d1;
        if(d2 >= s) {
            cout<<"Yes\n"<<i<<'\n';
            break;
        }
    }
    if(d2 < s) cout<<"No\n"<<d2<<'\n';
}