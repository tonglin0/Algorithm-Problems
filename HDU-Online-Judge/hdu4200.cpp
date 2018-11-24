#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int anss[109];
int a[109][109];
int x[109];
int n;
int ans;

int cal()
{
  int i,j,k=0,ans=0;
  for (i=n;i>=1;i--)
  {
    if (a[i][i])
    {
      x[i]=a[i][n+1];
      for (j=i+1;j<=n;j++)
        if (a[i][j])
          x[i]^=x[j];
    }
    else
      x[i]=anss[++k];
    if (x[i])
      ans++;
  }
  return ans;
}

void dfs(int k,int cnt)
{
  if (!cnt)
  {
    ans=min(ans,cal());
    return ;
  }
  anss[k]=1;
  dfs(k+1,cnt-1);
  anss[k]=0;
  dfs(k+1,cnt-1);
}

void gause(int n,int m)
{
  int i=1,jj=1,j=1,k,u,r;
  while(i<=n&&j<=m&&jj<=n)
  {
    r=i;
    for (u=i;u<=n;u++)
      if (a[u][j])
      {
        r=u;
        break;
      }
    if (a[r][j])
    {
      if (r!=i)
        for (k=j;k<=m+1;k++)
          swap(a[r][k],a[i][k]);
      for (u=i+1;u<=n;u++)
        if (a[u][j])
          for (k=j;k<=m+1;k++)
            a[u][k]^=a[i][k];
      i++;
      j++;
    }
    else
    {
      int val=n-jj+j;
      int ii;
      for (ii=1;ii<=n;ii++)
        swap(a[ii][j],a[ii][val]);
    }
    jj++;
  }
  r=i-1;
  for (k=i;k<=n;k++)
    if (a[k][m+1])
    {
      ans=-1;
      return ;
    }
  dfs(1,n-r);
}

int main()
{
  freopen("4200.in","r",stdin);
  freopen("4200.out","w",stdout);
  int d,i,j,ca,k;
  scanf("%d",&ca);
  while(ca--)
  {
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    memset(anss,0,sizeof(anss));
    ans=(int)1e9;
    scanf("%d%d",&n,&d);
    for (i=1;i<=n;i++)
      scanf("%d",&a[i][n+1]);
    for (i=1;i<=n;i++)
    {
      for (j=i-d;j<=i+d;j++)
        a[max(1,min(j,n))][i]=1;
    }
    gause(n,n);
    if (ans==-1)
      printf("impossible\n");
    else
      printf("%d\n",ans);
  }
  return 0;
}
