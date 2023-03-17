/*
3 2
1 2 1
1 2
1 3

*/
//cf 86 D
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, pair<int, int > >
#define f first
#define s second
int n, q, arr[200001], bi[200001], cnt[1000001], ans[200001];pii queries[200001];

bool sf(pii a, pii b)
{
	if(bi[a.f]==bi[b.f])
	{
		if(a.s.f==b.s.f) return a.f<b.f;
		if(a.f%2==0) return a.s.f<b.s.f;
		return a.s.f>b.s.f;
	}
	return bi[a.f]<bi[b.f];
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;int bsize=sqrt(n);int cur=0, nxt=0;;
	for(int i=0;i<1000001;i++) cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		cur++;
		if(cur==n) {cur=1;nxt++;}
		bi[i]=nxt;
	}
	for(int i=0;i<q;i++)
	{
		int l, r;cin>>l>>r;
		queries[i].f=l;queries[i].s.f=r;queries[i].s.s=i;
	}
	sort(queries, queries + q, sf);cur=0;
	int l, r;
	for(l=queries[0].f;l<=queries[0].s.f;l++)
	{
		cur+=(2*cnt[arr[l]] + 1)*arr[l];cnt[arr[l]]++;
	}
	ans[queries[0].s.s]=cur;
	l=queries[0].f;r=queries[0].s.f;
	for(int i=1;i<q;i++)
	{
		while(l>queries[i].f)
		{
			l++;cur+=(2*cnt[arr[l]]+1 )*arr[l];	cnt[arr[l]]++;
		}
		while(l<queries[i].f)
		{
			cur-=(2*cnt[arr[l]]-1 )*arr[l];l--;cnt[arr[l]]--;
		}
		while(r>queries[i].s.f)
		{
			cur-=(2*cnt[arr[r]]-1 )*arr[r];r--;cnt[arr[r]]--;
		}
		while(r<queries[i].s.f)
		{
			r++;cur+=(2*cnt[arr[r]]+1 )*arr[r];cnt[arr[r]]++;
		}
		ans[queries[i].s.s]=cur;
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}