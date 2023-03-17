//https://leetcode.com/problems/palindrome-partitioning-ii/description/
class Solution {
public:
    int expand(int c1, int c2, string s) {
        int rad = 0;
        while(c1 - rad >=0 && c2 + rad<s.length() && s[c1 - rad]==s[c2 + rad]) rad++;
        return rad-1; 
    }
    int minCut(string s) {
        int n = s.length();
        bool pal[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) pal[i][j]=0;
        }
        // ccaacabacb
        for(int i=0;i<n;i++) {
            int rad = expand(i, i, s); 
            int start = i-rad, fin = i + rad; 
            // cout<<i<<": "<<rad<<endl;
            pal[start][fin]=1;
            rad = expand(i, i+1, s); 
            // cout<<i<<" "<<i+1<<": "<<rad<<endl;
            if(rad!=-1) {start = i-rad; fin = i + rad+1;pal[start][fin]=1;}
        }
        for(int st=n-1;st>1;st--) {
            for(int i=0, j=i+ st;j<n;j++, i++) {
                pal[i+1][j-1]=max(pal[i+1][j-1], pal[i][j]);
            }
        }
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<=n;i++) {
            dp[i] = dp[i-1] + 1;
            for(int j=1;j<=i;j++) {
                if(pal[j-1][i-1]) dp[i]=min(dp[i], dp[j-1] + 1);
            }
            // cout<<dp[i]<<" ";
        }
        // cout<<endl<<pal[2][3]<<endl;
        return dp[n]-1;
    }
};
