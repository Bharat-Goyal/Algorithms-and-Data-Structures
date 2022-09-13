/*input
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
1 2
1 3
1 4
2 3
5 3
CF 375 D tree and queries. 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 100;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
#define initv for(int i=1;i<=n;i++) done[i]=0;
int n, q, col[N], occ[N];
class Segtree
{
	int tree[4*N], ql, qr, val;//tree[l, r] no of colours which have frequence >=l and <=r
	void upd(int i=1, int l=0, int r=n)
	{
		if(l>qr||r<ql) return;
		tree[i]+=val;
		if(l==r) return;
		int mid=(l+r)>>1;
		upd(2*i, l, mid);upd(2*i+1, mid+1, r);
	}
	int qry(int i=1, int l=0, int r=n)
	{
		if(l>qr||r<ql) return 0;
		if(l>=ql&&r<=qr) return tree[i];int mid=(l+r)/2;
		return qry(2*i, l, mid) + qry(2*i+1, mid+1, r);
	}
	public:
	void update(int ind, int change)
	{
		val=change;ql=qr=ind;
		if(ql>=0&&qr<=n) upd();
	}
	int query(int spos)
	{
		qr=n;ql=spos;return qry();
	}
};
Segtree tree;
int heavy[N], ans[N];
vector<int> adjlist[N];vector< pii > queries[N];bool done[N];
inline void changeocc(int pos, int val){
	tree.update(occ[pos], -1);occ[pos]+=val;
	tree.update(occ[pos], +1);
}
int dfs0(int i, int p)
{
	int ret=1;
	int mval=0;heavy[i]=0;
	for(auto j:adjlist[i])
	{
		if(j==p) continue;
		int temp=dfs0(j, i);
		if(temp>mval){
			mval=temp;heavy[i]=j;
		}
		ret+=temp;
	}
	return ret;
}
void extdfs(int i, int p, int val)
{
	for(auto j:adjlist[i]){
		if(j==p) continue;
		extdfs(j, i, val);
	}
	changeocc(col[i], val);
}
void dfs(int i, int p)
{
	//cout<<i<<endl;
	for(auto j:adjlist[i])
	{
		if(j==p||j==heavy[i]) continue;
		dfs(j, i);
		extdfs(j, i, -1);
	}
	if(heavy[i]) {dfs(heavy[i], i);}
	for(auto j:adjlist[i])
	{
		if(j==p||j==heavy[i]) continue;
		extdfs(j, i, 1);
	}
	changeocc(col[i], +1);
	if(done[i]) return;
	//cout<<i<<":";
	//for(int j=1;j<=3;j++) cout<<occ[j]<<" ";cout<<endl;
	//for(int j=1;j<=n;j++) cout<<tree.query(j)<<" ";cout<<endl<<endl;
	for(auto j:queries[i])
	{
		ans[j.s]=tree.query(j.f);
	}
	done[i]=1;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=0;i<N;i++) occ[i]=0;
	for(int i=1;i<=n;i++) cin>>col[i];
	for(int i=1;i<n;i++)
	{
		int u, v;cin>>u>>v;adjlist[u].push_back(v);adjlist[v].push_back(u);
	}	
	for(int i=1;i<=q;i++)
	{
		int v, k;cin>>v>>k;queries[v].push_back(mp(k, i));
	}
	for(int i=1;i<=n;i++) sort(queries[i].begin(), queries[i].end());
	dfs0(1, -1);
//	for(int i=1;i<=n;i++) cout<<heavy[i]<<" ";cout<<endl;
	dfs(1, -1);
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}