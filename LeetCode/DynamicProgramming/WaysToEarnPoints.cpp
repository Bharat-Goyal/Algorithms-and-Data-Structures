//https://leetcode.com/problems/number-of-ways-to-earn-points/description/
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        long long dp[51][target+1];
        for(int i=0;i<51;i++) {
            for(int j=0;j<=target;j++) dp[i][j]=0;
        }
        dp[0][0] = 1; 
        int n = types.size();
        int mod = 1e9 + 7;
        for(int i=1;i<=n;i++) {
            dp[i][0] = 1;
            for(int j=1;j<=target;j++) {
                for(int k=0;k*types[i-1][1]<=j && k<=types[i-1][0];k++) {
                    dp[i][j] += dp[i-1][j- k*types[i-1][1]];
                    dp[i][j]%=mod;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<dp[1][target];
        return dp[n][target];
    }
};
