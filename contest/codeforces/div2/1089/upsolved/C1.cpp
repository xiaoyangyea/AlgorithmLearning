#include<vector>
#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}
int main() {
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        vector<long long>a(n+1), b(n+1);
        for(int i = 1; i <= n; i ++) cin>>a[i];
        for(int i = 1; i <= n; i ++) cin>>b[i];
        int cnt = 0;
        if(gcd(a[1], a[2]) < a[1]) cnt ++;
        for(int i = 2; i <= n - 1; i ++) {
            long long x = gcd(a[i], a[i-1]),
                y = gcd(a[i], a[i+1]);
            if(x * y / gcd(x, y) < a[i]) cnt ++;
        }
        if(gcd(a[n], a[n-1]) < a[n]) cnt ++;
        cout<<cnt<<'\n';
    }
}