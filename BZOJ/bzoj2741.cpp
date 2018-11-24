#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 24005
using namespace std;

int K=31;
int root[MN];
int ch[MN*33][2];
int sum[MN*33];
int tot=0;
int a[MN],b[MN];
int sz,cnt;
int bl[MN];
int lastans;
int dp[120][12010];

void init()
{
	root[0]=0;
	sum[0]=ch[0][0]=ch[0][1]=0;
}

void update(int &r,int o,int x,int d)
{
    r=++tot;
	sum[r]=sum[o]+1;ch[r][0]=ch[o][0];ch[r][1]=ch[o][1];
	if (d<0)
		return ;
	int p=(x>>d)&1;
	update(ch[r][p],ch[o][p],x,d-1);
}

int query(int l,int r,int x,int d)
{
	if (d<0)
		return 0;
	int p=(x>>d)&1;
	int s=sum[ch[r][p^1]]-sum[ch[l][p^1]];
	if (s>0)
		return (1<<d)+query(ch[l][p^1],ch[r][p^1],x,d-1);
    else
		return query(ch[l][p],ch[r][p],x,d-1);
}

int getans(int l,int r)
{
	int t=(l-1)/sz+1+1;
	int ans=0;
	if (bl[l]!=bl[r])
		ans=dp[t][r];
	for (int i=l-1;i<=min(r,(t-1)*sz+1);i++)
		ans=max(ans,query(root[l-1],root[r],b[i],K));
	return ans;
}

int main()
{
	freopen("2741.in","r",stdin);
	freopen("2741.out","w",stdout);
	int n,i,j,m;
	scanf("%d%d",&n,&m);
	a[0]=0;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	init();
	b[0]=0;
	for (i=1;i<=n;i++)
		b[i]=b[i-1]^a[i];
	for (i=1;i<=n;i++)
		update(root[i],root[i-1],b[i],K);
	sz=(int)sqrt(n+0.5);
	cnt=(n-1)/sz+1;
	for (i=0;i<=n;i++)
		bl[i]=(i-1)/sz+1;
    for (j=1;j<=n;j++)
		for (i=1;i<=bl[j];i++)
			//dp[i][j]=max(dp[i][j-1],query(root[(j-1)*sz+1-1],root[i-1],b[i],K));
		    dp[i][j]=max(dp[i][j-1],query(root[(i-1)*sz+1-1],root[j-1],b[j],K));
	lastans=0;
	while(m--)
	{
		int l,r,x,y;
		scanf("%d%d",&x,&y);
		l=min((lastans%n+x%n)%n+1,(lastans%n+y%n)%n+1);
		r=max((lastans%n+x%n)%n+1,(lastans%n+y%n)%n+1);
		lastans=getans(l,r);
		printf("%d\n",lastans);
	}
	return 0;
}