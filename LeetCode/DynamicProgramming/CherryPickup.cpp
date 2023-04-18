//https://leetcode.com/problems/cherry-pickup/description/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); 
        if(n==1) return grid[0][0];
        int dp[n][n][2*n - 1];
        int low = -100000;
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++)
                for(int k=0;k<2*n-1;k++)
                    dp[i][j][k] = low;
        dp[0][0][0] = grid[0][0];
        for(int dist=1;dist<2*n-1;dist++) {
            for(int i=max(0, dist - n + 1);i<=dist && i<n;i++) {
                for(int j=max(0, dist - n + 1);j<=dist && j<n;j++) {
                    if(grid[i][dist-i]==-1 || grid[j][dist-j] == -1) 
continue;
                    if(i>0 && j>0) {
                        dp[i][j][dist] = max(dp[i][j][dist], 
dp[i-1][j-1][dist-1]);
                    }
                    if(i>0 && j<dist) {
                        dp[i][j][dist] = max(dp[i][j][dist], 
dp[i-1][j][dist-1]);
                    }
                    if(j>0 && i<dist) {
                        dp[i][j][dist] = max(dp[i][j][dist], 
dp[i][j-1][dist-1]);
                    }
                    if(i<dist && j<dist) {
                        dp[i][j][dist] = max(dp[i][j][dist], 
dp[i][j][dist-1]);
                    }
                    if(dp[i][j][dist] == low) continue;
                    if(i==j) dp[i][j][dist] += grid[i][dist-i];
                    else dp[i][j][dist] += grid[i][dist-i] + 
grid[j][dist-j];
                }
            }
        }
        return max(dp[n-1][n-1][2*n-2], 0);
    }
};
