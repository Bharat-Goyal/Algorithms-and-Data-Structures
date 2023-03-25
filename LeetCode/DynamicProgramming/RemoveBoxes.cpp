//https://leetcode.com/problems/remove-boxes/description/
class Solution {
    int dp[100][100][100];
    int snext[100];
    
public:
    int recurse(int i, int j, int k, vector<int>& boxes) {
        if(i>j || k>=boxes.size()) return 0;
        if(i==j) return (k+1)*(k+1);
        if(dp[i][j][k] != -1) return dp[i][j][k];
        dp[i][j][k] = (k+1)*(k+1) + recurse(i+1, j, 0, boxes);
        int nxt=snext[i];
        while(nxt<=j) {
            dp[i][j][k] = max(dp[i][j][k], recurse(nxt, j, k+1, boxes) + recurse(i+1, nxt-1, 0, boxes));
            nxt=snext[nxt];
        }
        return dp[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int cur[101];
        for(int i=0;i<101;i++) cur[i]=n+1;
        for(int i=n-1;i>=0;i--) {
            snext[i]=cur[boxes[i]];
            cur[boxes[i]] = i;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) 
                for(int k=0;k<n;k++) dp[i][j][k]=-1;
        }
        return recurse(0, n-1, 0, boxes);
    }
};
