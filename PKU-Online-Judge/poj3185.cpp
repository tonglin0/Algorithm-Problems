#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int a[45][45];
int anss[45];
int ans=(int)1e9;
int x[45];

int cal()
{
  int ans=0,i,j,k=0;
  for (i=20;i>=1;i--)
  {
    if (a[i][i])
    {
      x[i]=a[i][21];
      for (j=i+1;j<=20;j++)
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
  if (cnt==0)
    ans=min(ans,cal());
  else
  {
    anss[k]=1;
    dfs(k+1,cnt-1);
    anss[k]=0;
    dfs(k+1,cnt-1);
  }
}

void gause(int n,int m)
{
  int i=1,jj=1,j=1,r,k,u;
  while(i<=n&&j<=m&&jj<=n)
  {
    r=i;
    for (k=i;k<=n;k++)
      if (a[k][j])
      {
        r=k;
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
      int val=m-jj+j;
      for (int ii=1;ii<=n;ii++)
        swap(a[ii][val],a[ii][j]);
    }
    jj++;
  }
  i--;
  dfs(1,n-i);
}

int main()
{
  freopen("3185.in","r",stdin);
  freopen("3185.out","w",stdout);
  int i,j,k,m;
  memset(a,0,sizeof(a));
  memset(x,0,sizeof(x));
  for (i=1;i<=20;i++)
    scanf("%d",&a[i][21]);
  for (i=1;i<=20;i++)
  {
    a[i][i]=1;
    if (i>1)
      a[i][i-1]=1;
    if (i<20)
      a[i][i+1]=1;
  }
  memset(anss,0,sizeof(anss));
  gause(20,20);
  printf("%d\n",ans);
  return 0;
}
