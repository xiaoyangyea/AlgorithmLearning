#include<vector>
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        vector<int>a(n), b(n), c(n);
        for(int i = 0; i < n; i ++) cin>>a[i];
        for(int i = 0; i < n; i ++) cin>>b[i];
        for(int i = 0; i < n; i ++) cin>>c[i];
        int cnt_1 = 0, cnt_2 = 0;
        vector<int>dp(n+1);
        for(int i = 0; i < n; i ++) {
            bool flag = true;
            for(int j = 0; j < n; j ++)
                if(a[j] >= b[(j+i) % n]) {
                    flag = false; 
                    break;
                }
            if(flag) cnt_1 ++;
        }
        for(int i = 0; i < n; i ++) {
            bool flag = true;
            for(int j = 0; j < n; j ++)
                if(b[j] >= c[(j+i) % n]) {
                    flag = false;
                    break;
                }
            if(flag) cnt_2 ++;
        }
        cout<<cnt_1<<' '<<cnt_2<<'\n';
        cout<<cnt_1 * cnt_2 * n<<'\n';
    }
}