/*input

*/
//Ilya and tree: https://www.hackerearth.com/problem/algorithm/illya-and-tree-1/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define f first
#define s second
inline pii mp(int a, int b)
{
	pii temp;temp.f=a;temp.s=b;return temp;
}
int n, q;vector<int> adjlist[100001];int add[400001], mult[400001], sub[400001], tree[400001], dsum[400001];
int cost[100001], start[100001], fin[100001], cur, depth[100001];
vector<int> nodes;
void dfs(int i)
{
	start[i]=cur++;node.push_back(i);
	for(auto j:adjlist[i])
	{
		if(start[j]==-1) {depth[j]=depth[i]+1;dfs(j);}
	}
	fin[i]=cur-1;
}
void build(int i, int l, int r)
{
	mult[i]=add[i]=sub[i]=0;
	if(l==r)
	{
		int tn=node[l-1];
		dsum[i]=depth[tn];
		tree[i]+=cost[tn];return;
	}
	int mid=(l+r)/2;
	build(2*i, l, mid);build(2*i+1, mid+1, r);
	tree[i]=tree[2*i]+tree[2*i+1];
	dsum[i]=dsum[2*i] + dsum[2*i+1];
}
int ql, qr, addq, multq, subq;
void prop(int i, int l, int r)
{
	add[2*i]+=add[i];
	sub[2*i]+=sub[i];
	mult[2*i]+=mult[i];
	add[2*i+1]+=add[i];
	sub[2*i+1]+=sub[i];
	mult[2*i+1]+=mult[i];
	tree[i]+=dsum[i]*mult[i] +(add-sub)*(r-l+1)
	add[i]=sub[i]=mult[i]=0;
}
void update(int i, int l, int r)
{
	if(l!=r)
	{
		prop(i, l, r);
	}
	else
	{
		tree[i]+=dsum[i]*mult[i] +(add-sub)*(r-l+1)
			add[i]=sub[i]=mult[i]=0;
	}
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr)
	{
		sub[i]+=subq;add[i]+=addq;mult[i]+=multq;
		if(l!=r)
		{
			prop(i, l, r);
		}
		else
		{
			tree[i]+=dsum[i]*mult[i] +(add-sub)*(r-l+1)
			add[i]=sub[i]=mult[i]=0;
		}
		return;
	}
	int mid=(l+r)/2;
	update(2*i, l, mid);update(2*i+1, mid+1, r);
	tree[i]=tree[2*i] + tree[2*i+1];
}
int query(int i, int l, int r)
{
	if(l>qr||r<ql) return 0;
	if(l!=r)
	{
		prop(i, l, r);
	}
	else
	{
		tree[i]+=dsum[i]*mult[i] +(add-sub)*(r-l+1)
			add[i]=sub[i]=mult[i]=0;
	}
	if(l>=ql&&r<=qr) return tree[i];
	int mid=(l+r)/2;
	return query(2*i, l, mid) + query(2*i+1, mid+1, r);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int u, v;cin>>u>>v;
		adjlist[u].push_back(v);
		adjilst[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];start[i]=-1;
	}
	depth[1]=0;
	cur=1;dfs(1);
	build(1, 1, cur-1);
	while(q--)
	{
		int t;cin>>t;
		if(t==1)
		{
			int v;cin>>v>>addq>>multq;
			subq=depth[v]*multq;ql=start[v];qr=fin[v];
			update(1, 1, cur-1);
		}
		else
		{
			int v;cin>>v;qr=start[v];
			
		}	
	}
}