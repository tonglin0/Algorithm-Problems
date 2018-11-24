#include<cstdio>
#include<iostream>
#include<algorithm>
#define lint long long
#define MN 200003
#define INF (int)1e9
using namespace std;

int v[MN],w[MN],li[MN],ri[MN];
int sumj[MN];
lint sumv[MN];

lint Abs(lint a){return a>0?a:-a;}
lint Min(lint a,lint b){return a>b?a:b;}

lint get_y(int n,int m,int mid)
{
	int i;
	for (i=0;i<=n;i++)	sumj[i]=sumv[i]=0;
	for (i=1;i<=n;i++)
		if (w[i]>=mid)
		{
			sumj[i]=1;
			sumv[i]=v[i];
		}
	for (i=1;i<=n;i++)
	{
		sumj[i]+=sumj[i-1];
		sumv[i]+=sumv[i-1];
	}
	lint y=0;
	for (i=1;i<=m;i++)
		y+=(lint)(sumj[ri[i]]-sumj[li[i]-1])*(sumv[ri[i]]-sumv[li[i]-1]);
	return y;	
}

int main()
{
	freopen("1314.in","r",stdin);
	freopen("1314.out","w",stdout);
	int n,m,i,j,l=INF,r=0;
	lint s;
	scanf("%d%d",&n,&m);
	cin>>s;//scanf("%lld",&s);
	for (i=1;i<=n;i++) 
	{
		scanf("%d%d",&w[i],&v[i]);
		l=min(l,w[i]);
		r=max(r,w[i]);
	}
	r++;
	for (i=1;i<=m;i++) 	scanf("%d%d",&li[i],&ri[i]);
	while(l<r)
	{
		int mid=l+r>>1;
		lint y=get_y(n,m,mid);
		if (s-y<0)
			l=mid+1;
		else
			r=mid;
	}
	lint ans=Abs(s-get_y(n,m,l));
	ans=Min(ans,Abs(s-get_y(n,m,l-1)));
	cout<<ans<<endl;//printf("%I64d\n",ans);
	return 0;
}
