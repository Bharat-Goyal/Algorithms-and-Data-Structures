/*input
6 3
11
11
11
24
26
100

output:299
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[8001][801], n, m, pref[8001];
int cost(int i, int j)
{
    return (pref[i]-pref[j])*(i-j);
}
void solve(int l, int r, int ll, int rl, int lvl)
{
    if(r<l) return;
    int mid=(l+r)>>1;dp[mid][lvl]=1e18;int pos;
    for(int i=ll;i<=min(rl, mid);i++)
    {
        if(dp[i][lvl-1] + cost(mid, i)<dp[mid][lvl])
        {
            pos=i;dp[mid][lvl]=dp[i][lvl-1] + cost(mid, i);
        }
    }
    solve(l, mid-1, ll, pos, lvl);solve(mid+1, r, pos, rl, lvl);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;pref[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>pref[i];pref[i]+=pref[i-1];dp[i][1]=pref[i]*i;
    }
    for(int i=2;i<=m;i++) solve(1, n, 1, n, i);
    
    //cout<<dp[m-1][m]<<endl;
    cout<<dp[n][m];
}   