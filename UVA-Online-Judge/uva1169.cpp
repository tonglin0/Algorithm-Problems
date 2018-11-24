#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MN 100009
using namespace std;
int c;
int x[MN],y[MN],w[MN];
int ws[MN],dis[MN],dis0[MN];
int dp[MN];
int q[MN<<1];
int f,r;

int Abs(int x){return x>=0?x:-x;}

int func(int x)
{
  return dp[x]+dis0[x+1]-dis[x+1];
}

int main()
{
  freopen("1169.in","r",stdin);
  freopen("1169.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&c);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d%d",&x[i],&y[i],&w[i]);
    ws[0]=0;ws[1]=w[1];
    dis0[1]=x[1]+y[1];
    dis[1]=x[1]+y[1];
    dis[0]=dis0[0]=0;
	for (i=2;i<=n;i++)
    {
      ws[i]=ws[i-1]+w[i];
      dis0[i]=x[i]+y[i];
      dis[i]=dis[i-1]+(Abs(x[i]-x[i-1])+Abs(y[i]-y[i-1]));
	}
	f=1;r=1;
	q[r]=0;
	dp[0]=0;
	for (i=1;i<=n;i++)
	{
	  while(f<=r&&ws[i]-ws[q[f]]>c)
	    f++;
	  j=q[f];
	  dp[i]=dp[j]+dis0[j+1]-dis[j+1]+dis[i]+dis0[i];
	  while(r>=f&&func(i)<=func(q[r]))
	    r--;
	  q[++r]=i;
	}
	printf("%d\n",dp[n]);
	if (ca)
	  printf("\n");
  }
  return 0;
}
