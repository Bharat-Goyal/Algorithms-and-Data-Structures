/*input
https://www.hackerrank.com/challenges/bike-racers/problem
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300;
#define int long long
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair
int n, m, k;
pii bike[N], biker[N];
vector< pii > adjlist[N];int match[N];
int wt;bool visited[N];
int aug(int i)
{
    if(visited[i]) return 0;
    visited[i]=1;
    for(auto j:adjlist[i])
    {
        if(j.s>wt) continue;
        if(match[j.f]==-1||aug(match[j.f]))
        {
            match[j.f]=i;return 1;
        }
    }
    return 0;
}
bool p(int x)
{
    for(int i=1;i<=m;i++) match[i]=-1;
    wt=x;int ans=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++) visited[j]=0;
        if(aug(i)) ans++;
    }
//    cout<<ans<<endl;
    return ans>=k;
}
void solve()
{   
    int low=0, high=1e17;
/*    for(int i=1;i<=n;i++)
    {
    	cout<<i<<": ";
    	for(auto j:adjlist[i]) cout<<j.f<<", "<<j.s<<"\t";cout<<endl;
    }
    p(1000000000);*/
    while(low<high)
    {
        int mid=(low+high)/2;
        if(p(mid)) high=mid;
        else low=mid+1;
    }
    cout<<low;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>bike[i].f>>bike[i].s;
    for(int i=1;i<=m;i++) cin>>biker[i].f>>biker[i].s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            adjlist[i].push_back(  
                mp(j, pow(bike[i].f - biker[j].f, 2) + pow(bike[i].s - biker[j].s, 2))
            );
        }
    }
    solve();
}
