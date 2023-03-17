//https://leetcode.com/problems/burst-balloons/description/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int dp[302][302]; 
        int n=nums.size(); 
        for(int i=0;i<=n+1;i++) {
            for(int j=0;j<=n+1;j++) dp[i][j] = 0;
        }
        nums.insert(nums.begin(), 1);nums.push_back(1);
        for(int t=2;t<=n+1;t++) {
            for(int i=0, j=i+t;j<=n+1;j++, i++) {
                for(int k=i+1;k<j;k++) {
                    dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n+1];
    }
};
