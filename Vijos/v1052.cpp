#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define lint long long
#define INF (int)1e9
using namespace std;

double a[103][103];

void gause(int n,int m)
{
  for (int i=1;i<=n;i++)
  {
    int r=i;
    for (int k=i+1;k<=n;k++)
      if (fabs(a[k][i])>fabs(a[r][i]))
        r=k;
    if (r!=i)
      for (int j=i;j<=m+1;j++)
        swap(a[i][j],a[r][j]);
    for (int u=i+1;u<=n;u++)
      for (int k=m+1;k>=i;k--)
        a[u][k]-=a[u][i]*a[i][k]/a[i][i];
  }
  for (int i=n;i>=1;i--)
  {
    for (int j=i+1;j<=n;j++)
      a[i][n+1]-=a[i][j]*a[j][n+1];
    a[i][n+1]/=a[i][i];
  }
}

int main()
{
  freopen("1052.in","r",stdin);
  freopen("1052.out","w",stdout);
  int n,m,i,j,k,ca;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n+1;j++)
      scanf("%lf",&a[i][j]);
  gause(n,n);
  for (i=1;i<=n;i++)
    if (i==1)
      printf("%d",(int)(a[i][n+1]+0.5));
    else
      printf(" %d",(int)(a[i][n+1]+0.5));
  printf("\n");
  return 0;
}

