#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

bool a[103][103];

int main()
{
  freopen("3660.in","r",stdin);
  freopen("3660.out","w",stdout);
  int n,i,j,m;
  scanf("%d%d",&n,&m);
  memset(a,0,sizeof(a));
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    a[u][v]=true;
  }
  int ans=0;
  for (int k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (a[i][k]&&a[k][j]) a[i][j]=true;
  for (i=1;i<=n;i++)
  {
    int k=0;
    for (j=1;j<=n;j++)
      if (a[i][j]||a[j][i]) k++;
    if (k==n-1) ans++;
  }
  printf("%d\n",ans);
  return 0;
}
