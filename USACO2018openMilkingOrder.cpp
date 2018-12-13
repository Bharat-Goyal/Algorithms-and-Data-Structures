#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 100;
const int mod=1e9 + 7;
#define int long long
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
int n, m;
vector<int> cond[N];
vector<int> adjlist[N];
bool bv[N], visited[N];int indeg[N];vector<int> toposort;set<int> q;
void init()
{
	for(int i=1;i<=n;i++) 
	{
		adjlist[i].clear();visited[i]=0;bv[i]=0;indeg[i]=0;
	}
}
bool dfs(int i)
{
	bv[i]=visited[i]=1;
	for(auto j:adjlist[i])
	{
		if(bv[j]) return true;
		if(visited[j]) continue;
		if(dfs(j)) return true;
	}
	bv[i]=0;return false;
}
void fill(int x)
{
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<cond[i].size();j++)
		{
			adjlist[cond[i][j-1]].push_back(cond[i][j]);
			indeg[cond[i][j]]++;
		}
	}
}
bool p(int x)
{
	init();fill(x);
	for(int i=1;i<=n;i++)
	{
		if(dfs(i)) return false;
	}
	return true;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a;cin>>a;
		while(a--)
		{
			int ft;cin>>ft;
			cond[i].push_back(ft);
		}
	}
	int low=0, high=m;
	while(low<high)
	{
		int mid=(low+high+1)/2;
		if(p(mid)) low=mid;
		else high=mid-1;
	}
	init();fill(low);
	for(int i=1;i<=n;i++) 
		if(indeg[i]==0) q.insert(i);
	while(!q.empty())
	{
		int cur=(*q.begin());q.erase(q.begin());
		toposort.push_back(cur);
		for(auto j:adjlist[cur])
		{
			indeg[j]--;
			if(indeg[j]==0) q.insert(j);
		}
	}
	for(int i=0;i<toposort.size();i++) 
	{
		cout<<toposort[i];
		if(i!=toposort.size()-1) cout<<" ";
	}
}