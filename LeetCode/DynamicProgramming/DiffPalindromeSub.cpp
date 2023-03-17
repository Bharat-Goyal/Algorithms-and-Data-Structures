//https://leetcode.com/problems/count-different-palindromic-subsequences/description/
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<n;i++){ 
            for(int j=0;j<n;j++) dp[i][j]=0;
            dp[i][i]=1;}
        int prev[n][26];
        int snext[n][26];
        const int mod =1e9 + 7;
        for(int i=0;i<26;i++) prev[0][i]=snext[n-1][i]=-1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<26;j++) prev[i][j] = prev[i-1][j]; 
            prev[i][s[i-1]-'a'] = i-1;
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<26;j++) snext[i][j] = snext[i+1][j];
            snext[i][s[i+1]-'a']=i+1;
        }
        for(int len=2;len<=n;len++) {
            for(int i=0, j=i+len-1;j<n;j++, i++) {
                
                if(s[i]==s[j]) {//Cuz the single character palindrome is already over!
                    int nx = snext[i][s[i]-'a'], px = prev[j][s[i]-'a'];
                    int v1 = 0;
                    if(nx==j) {
                        v1 = -2;
                    }
                    else if(nx==px) {
                        v1 = -1;
                    } 
                    else {
                        v1 = dp[nx+1][px-1];
                    }
                    dp[i][j] += (2*dp[i+1][j-1])%mod- v1;
                    dp[i][j]%=mod;
                    dp[i][j]+=mod;
                    dp[i][j]%=mod;
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                    dp[i][j]%=mod;
                    dp[i][j]+=mod;
                    dp[i][j]%=mod; 
                }
                // cout<<i<<" "<<j<<"="<<dp[i][j]<<endl; 
            }
        }
        return dp[0][n-1];
    }
};
/*
*/
