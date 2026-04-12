#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<stack<int>>s(n + 1);
        for(int i = 0; i < n; i ++)
            cin>>arr[i], s[arr[i]].push(i);
        int cur = n + 1, res = 0;
        for(int i = n; i >= 0; i --) {
            while(!s[i].empty()) {
                if(cur > s[i].top()) {
                    cur = s[i].top();
                    res ++;
                } 
                s[i].pop();
            }
        }
        cout<<res<<'\n';
    }
}