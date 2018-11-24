#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

bool vis[1000004];
double f[1000004];
int c[1000000];
int p;

double dp(int x)
{
  if (x==1)
    return 0.0;
  if (vis[x])
    return f[x];
  vis[x]=true;
  f[x]=0;
  int px=0,gx=0;
  for (int i=1;i<=p&&c[i]<=x;i++)
  {
    px++;
    if (x%c[i]==0)
    {
      gx++;
      f[x]+=dp(x/c[i]);
	}
  }
  f[x]=(f[x]+px)/gx;
  return f[x];
}

int main()
{
  freopen("11762.in","r",stdin);
  freopen("11762.out","w",stdout);
  int ca,ii,n,i,k,m;
  long long j;
  p=0;
  memset(vis,0,sizeof(vis));
  for (i=2;i<=1000000;i++)
    if (!vis[i])
    {
      c[++p]=i;
      for (j=(long long)i*i;j<=1000000;j+=(long long)i)
        vis[j]=true;
	}
  memset(vis,0,sizeof(vis));
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    scanf("%d",&n);
    printf("Case %d: %.10lf\n",ii,dp(n));
  }
  return 0;
}
