//https://leetcode.com/problems/strange-printer/description/
class Solution {
public:
    int strangePrinter(string s) {
        int dp[100][100][26];
        int n =s.length(); 
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<26;k++) {
                    dp[i][j][k] = 1100;
                    
                }
            }
            dp[i][i][s[i] - 'a'] = 0;
        }
        int add=0, ans=n;
        for(int l=2;l<=n;l++) {
            for(int i=0, j=i+l-1;j<n;i++, j++) {
                for(int k=0;k<26;k++) {
                    if(s[i]==s[j]) {
                        if(s[i]-'a'==k) add =0;
                        else add =1;
                    }
                    else {
                        add=2;
                        if(s[i]-'a'==k) add--;
                        if(s[j] - 'a' ==k) add--;
                    }
                   for(int div = i;div<j;div++) {
                       dp[i][j][k] = min(dp[i][j][k], dp[i][div][s[i]-'a'] 
+ dp[div+1][j][s[j]-'a'] + add);
                   } 
                }
            }
        }
        for(int k=0;k<26;k++) ans=min(ans, dp[0][n-1][k]);
        return ans+1;
    }
};
