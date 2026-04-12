#include<vector>
#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    vector<int>arr(n+1);
    int tempb;
    for(int i = 1; i <= n; i ++) cin>>arr[i];
    vector<int> cnt(5, 0);
    for(int i = 0; i < m; i ++) {
        cin>>tempb;
        cnt[tempb] ++;
    }
    vector<vector<vector<vector<long long>>>>dp(cnt[1] + 1, vector<vector<vector<long long>>>(cnt[2] + 1, vector<vector<long long>>(cnt[3] + 1, vector<long long>(cnt[4] + 1, 0))));
    dp[0][0][0][0] = arr[1];
    for(int i = 0; i <= cnt[1]; i ++)
        for(int j = 0; j <= cnt[2]; j ++)
            for(int k = 0; k <= cnt[3]; k ++)
                for(int l = 0; l <= cnt[4]; l ++) {
                    if(i == 0 && j == 0 && k == 0 && l == 0)
                        continue;
                    long long cur = dp[i][j][k][l];int pos = 1 + i + 2*j + 3*k + 4*l;
                    if(i != 0) cur = max(cur, dp[i-1][j][k][l] + arr[pos]);
                    if(j != 0) cur = max(cur, dp[i][j-1][k][l] + arr[pos]);
                    if(k != 0) cur = max(cur, dp[i][j][k-1][l] + arr[pos]);
                    if(l != 0) cur = max(cur, dp[i][j][k][l-1] + arr[pos]);
                    dp[i][j][k][l] = cur;
                }
    cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<'\n';
}