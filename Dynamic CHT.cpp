/*input

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
struct node{
	int m, c;
	//m=rate, c=sev - start*m
};
struct comp
{
	bool operator()(node a, node b)
	{
		if(a.rate==b.rate) return a.sev<=b.sev;
		return a.rate<b.rate;
	}
};
multiset<node, comp> vals;
node arr[N];int n;
void update(int ind)
{

}
int query(int x)
{

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{

	}
}