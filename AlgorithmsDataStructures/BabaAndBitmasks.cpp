/*input
2
2
536870912 536870911
2
536870912 536870911

*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int unsigned long long
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> pbds;
int n, arr[1000001], ans;stack<int> st;
int f(int a, int b)
{
	return ((a|b)*(a|b)) - ((a&b)*(a&b));
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--)
	{
		cin>>n;ans=0;
		for(int i=1;i<=n;i++) cin>>arr[i];
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++)
		{
			while(!st.empty()&&st.top()>=arr[i])
			{
				st.pop();
			}
			if(!st.empty())
			{
				ans=max(ans, f(st.top(), arr[i]));
			}
			st.push(arr[i]);
		}
		while(!st.empty()) st.pop();
		for(int i=n;i>=1;i--)
		{
			while(!st.empty()&&st.top()>=arr[i])
			{
				st.pop();
			}
			if(!st.empty())
			{
				ans=max(ans, f(st.top(), arr[i]));
			}
			st.push(arr[i]);
		}
		cout<<ans<<endl;
	}
}