/*input
3
3 2 1
*/
//subarray medians
#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 10;
const int N2=350;
#define int long long
#define pii pair<int, int>
#define f first
#define s second
inline pii mp(int a, int b)
{
	pii temp;temp.f=a;temp.s=b;return temp;
}
int n, bsize, arr[N], cur[N], bl[N], br[N], binda[N]; 
int val[N2][3*N2], qar[N], startin[N2], finin[N2], tot[N2];
int pos[N];
int getind(int x)
{
	if(x>=0) return x;
	if(abs(x)>bsize) return 0;
	return bsize + abs(x); 
}
void update(int l, int r, int ind)
{
	int sum=0;
	for(int i=0;i<3*N2;i++) val[ind][i]=0;
	tot[ind]=0;
	for(int i=l;i<=r;i++)
	{
		sum+=qar[i];
		val[ind][getind(sum)]++;
	}
	tot[ind]=sum;
}
int solve()
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		pos[arr[i]]=i;qar[i]=-1;
	}
	bsize=sqrt(n);
	int inc=0, cur=0;
	for(int i=1;i<=n;i++)
	{
		if(inc==bsize)
		{
			finin[cur]=i-1;
			cur++;inc=0;
		}
		if(inc==0) startin[cur]=i;
		binda[i]=cur;inc++;qar[i]=-1;
		if(i==n) finin[cur]=i;
	}
	cur++;
	for(int i=0;i<cur;i++)
	{
		update(startin[i], finin[i], i);
	}
	for(int i=1;i<=n;i++)
	{
		qar[pos[i]]=0;
		update(startin[binda[pos[i]]], finin[binda[pos[i]]], binda[pos[i]]);
		int cursum=0;
		for(int j=pos[i];j<=finin[binda[pos[i]]];j++)
		{
			cursum+=qar[j];
			if(cursum==0||cursum==1) ret++; 
		}
		for(int j=binda[pos[i]]+1;j<cur;j++)
		{
			int i1=val[j][getind(0-cursum)], i2=val[j][getind(0-cursum + 1)];
			if(abs(0-cursum)>bsize) i1=0;
			if(abs(0 - cursum + 1)>bsize) i2=0;
			ret+=i1 + i2;
			cursum+=tot[j];
		}
		qar[pos[i]]=1;
		update(startin[binda[pos[i]]], finin[binda[pos[i]]], binda[pos[i]]);
	}
	return ret;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int ans=solve();
	for(int l=1, r=n;l<=r;l++, r--)
	{
		swap(arr[l], arr[r]);
	}
	ans+=solve();cout<<ans-n;
}
