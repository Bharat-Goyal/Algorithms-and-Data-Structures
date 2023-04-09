//https://leetcode.com/problems/unique-paths/description/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long ret = 1;
        n--;m--;
        if(m>n) swap(m, n);
        int div =2;
        for(int i=n+1;i<=m+n;i++) {
            ret*= i;
            while(ret%div==0 && div<=m) {
                ret/=div++;
            }
        }
        return (int)ret;
    }
};
