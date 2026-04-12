#include<vector>
#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> table(n, vector<int>(m)), 
                        col(n, vector<int>(m, 0)), 
                        row(n, vector<int>(m, 0)), 
                        dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin>>table[i][j],
            dp[i][j] = table[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 1; j < m; j ++)
            row[i][j] = table[i][j] > 0 ? row[i][j-1] + 1 : 0;
    for(int i = 0; i < m; i ++) 
        for(int j = 1; j < n; j ++)
            col[j][i] = table[j][i] > 0 ? col[j-1][i] + 1 : 0;
    int curMax = 0;
    for(int i = 1; i < n; i ++) 
        for(int j = 1; j < m; j ++)
            if(row[i][j] >= dp[i-1][j-1] && col[j][i] >= dp[i-1][j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1,
                curMax = max(curMax, dp[i][j]);
    cout<<curMax * curMax<<'\n';
}