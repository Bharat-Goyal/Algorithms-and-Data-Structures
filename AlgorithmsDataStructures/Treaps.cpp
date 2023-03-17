/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pnode node*
struct node
{
	int val, prio;pnode l, r;
};
pnode root;int q;
void split(pnode t, pnode &l, pnode &r, int x)
{
	if(!t)
	{
		l=r=NULL;
	}
	else if(t->val>x)
	{
		split(t->l, l, t->l, x);r=t;
	}
	else
	{
		split(t->r, t->r, r, x);l=t;
	}
}
void merge(pnode &t, pnode l, pnode r)
{
	if(l==NULL||r==NULL)
	{
		t=(l)?l:r;
	}
	else if(l->prio>r->prio)
	{
		merge(l->r, l->r, r);t=l;
	}
	else
	{
		merge(r->l, l, r->l);t=r;
	}
}
pnode init(int val)
{
	srand(val);
	pnode temp=new node;temp->val=val;temp->prio=rand();return temp;
}
void insert(pnode &t, pnode ins)
{
	if(t->prio<=ins->prio)
	{
		split(t, ins->l, ins->r, ins->val);t=ins;
	}
	else
	{
		if(t->val<=ins->val)
		{
			insert(t->l, ins);
		}
		else
		{
			insert(t->r, ins);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	root=new node;
	cin>>q;
	while(q--){
		char op;cin>>op;
		int x;
		if(op=='I')
		{
			cin>>x;
		}
		if(op=='D')
		{
			cin>>x;
		}
		if(op=='K')
		{
			
		}
		if(op=='C')
		{
			cin>>x;
		}
	}
}


