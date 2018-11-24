#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[103][103];
int f[103];

int main()
{
  freopen("1712.in","r",stdin);
  freopen("1712.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2&&(n+m))
  {
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++)
      for (j=m;j>=0;j--)
        for (k=1;k<=j;k++)
          f[j]=max(f[j],f[j-k]+a[i][k]);
    printf("%d\n",f[m]);
  }
  return 0;
}
