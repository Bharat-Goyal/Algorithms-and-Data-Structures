/*input
5 5
1 2
2 3
3 1
4 1
5 2

*/
//cf 1000E
//ceoi 17 one way roads has lca on bridge tree. oj.uz
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define pii pair<int, int>
#define f first
#define s second
inline pii mp(int a, int b)
{
	pii temp;temp.f=a;temp.s=b;return temp;
}
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> pbds;
int n, m, dp[300001][2], low[300001], disc[300001], t;vector<int> adj[300001];
set<int>  adjlist[300001];int compno[300001];
vector<int> nadj[300001];
void dfs(int i, int p)
{
	disc[i]=t;low[i]=t++;
	for(int k=0;k<adj[i].size();k++)
	{
		int j=adj[i][k];//cout<<j<<endl;
		if(disc[j]!=0)
		{
			if(j!=p) low[i]=min(low[i], disc[j]);
		}
		else
		{
			dfs(j, i);
			low[i]=min(low[i], low[j]);
			if(low[j]>disc[i])
			{
				adjlist[i].insert(j);adjlist[j].insert(i);
			}
		}
	}
}
void dfs2(int i, int p)
{
	disc[i]=1;compno[i]=t;
	for(auto j:adj[i])
	{
		if(disc[j]!=0||adjlist[i].find(j)!=adjlist[i].end()) continue;
		dfs2(j, i);
	}
}
void dfs3(int i, int p)
{
	int m1=0, m2=0;dp[i][0]=dp[i][1]=0;
	for(auto j:nadj[i])
	{
		if(j==p) continue;
		dfs3(j, i);
		dp[i][0]=max(dp[i][0], dp[j][0] + 1);
		if(m1<dp[j][0]+1)
		{
			m2=m1;m1=dp[j][0]+1;
		}
		else if(m2<dp[j][0]+1) m2=dp[j][0]+1;
	}
	dp[i][1]=m1 + m2;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;t=0;
	while(m--)
	{
		int u, v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		low[i]=disc[i]=0;
	}
	t=1;
	dfs(1, -1);
	for(int i=1;i<=n;i++)
	{
		disc[i]=0;
	}
	t=1;
	for(int i=1;i<=n;i++)
		{
			if(disc[i]==0) {dfs2(i, -1);t++;}
		}
	for(int i=1;i<=n;i++)
	{
		for(auto j:adjlist[i])
		{
			nadj[compno[i]].push_back(compno[j]);
		}
	}
	dfs3(1, -1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans, dp[i][1]);
	}
	cout<<ans;
}