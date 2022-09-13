/*input
https://www.spoj.com/problems/MKTHNUM/
*/
#include<bits/stdc++.h>
using namespace std; 
#define int long long
int tree[2060964], root[100001], L[2060964], R[2060964], nxt, ql, qr, a[100001], n, k;
vector<int> arr;int m, pos[100001];
void build(int i, int l, int r)
{
	tree[i]=0;
	if(l==r)
	{
		return;
	}
	L[i]=nxt++;R[i]=nxt++;
	int mid=(l+r)/2;
	build(L[i], l, mid);build(R[i], mid+1, r);
}
void update(int oi, int l, int r, int ni)
{
	tree[ni]=tree[oi]+1;
	if(l==r) return;
	int mid=(l+r)/2;L[ni]=L[oi];R[ni]=R[oi];
	if(ql<=mid)
	{
		L[ni]=nxt++;update(L[oi], l, mid, L[ni]);
	}
	else
	{
		R[ni]=nxt++;update(R[oi], mid+1, r, R[ni]);	
	}
}
int query(int oi, int ni, int l, int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	//cout<<tree[L[ni]] - tree[L[oi]]<<endl;
	if(tree[L[ni]] - tree[L[oi]]>=k) return query(L[oi], L[ni], l, mid);
	k-=tree[L[ni]] - tree[L[oi]];
	return query(R[oi], R[ni], mid+1, r);
}
bool sf(int f, int c)
{
	return a[f]<a[c];
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];arr.push_back(i);
	}
	sort(arr.begin(), arr.end(), sf);
	for(int i=0;i<arr.size();i++)
	{
		pos[arr[i]]=i;
	}
	root[0]=0;nxt=1;
	build(0, 0, n-1);
	for(int i=1;i<=n;i++)
	{
		root[i]=nxt++;ql=pos[i];tree[root[i]]=tree[root[i-1]]+1;
		int mid=(n-1)/2;L[root[i]]=L[root[i-1]];R[root[i]]=R[root[i-1]];
		if(ql<=mid)
		{
			L[root[i]]=nxt++;update(L[root[i-1]], 0, mid, L[root[i]]);
		}
		else
		{
			R[root[i]]=nxt++;update(R[root[i-1]], mid+1, n-1, R[root[i]]);	
		}
	}
	while(m--)
	{
		cin>>ql>>qr>>k;
//		cout<<tree[root[ql-1]]<<" "<<tree[root[qr]]<<endl;
		cout<<a[arr[query(root[ql-1], root[qr], 0, n-1)]]<<endl;//cout<<endl<<endl;
	}
}
