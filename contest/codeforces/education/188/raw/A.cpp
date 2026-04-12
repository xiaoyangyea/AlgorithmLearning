#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t --) {
        int n, cur = 0;
        string s;
        cin>>n>>s;
        vector<int>arr(n, 0);
        for(int i = 0; i < n; i ++) {
            arr[cur] ++;
            if(s[cur] == 'R') cur ++;
            else cur --;
        }
        arr[cur] ++;
        int cnt = 0;
        for(int i = 0; i < n; i ++)
            cnt += arr[i] != 0;
        cout<<cnt<<'\n';
    }
}