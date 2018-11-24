#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
#define lint long long
#define eps 1e-8
#define INF (int)1e9
#define MN 505 
using namespace std;

int a[505][505],b[MN][MN],c[MN][MN];
int r[MN][2];
int tmp[MN][2],tmp2[MN][2],tmp3[MN][2];

int random(int x)
{
  return x*(rand()/(double)RAND_MAX);
}

int main()
{
  freopen("3318.in","r",stdin);
  freopen("3318.out","w",stdout);
  int n,m,i,j,k;
  srand(time(NULL));
  while(scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&b[i][j]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&c[i][j]);
    for (i=1;i<=n;i++)
      r[i][1]=random(10)+1;
    for (i=1;i<=n;i++)
      for (j=1;j<=1;j++)
        tmp[i][j]=tmp2[i][j]=tmp3[i][j]=0;
	for (i=1;i<=n;i++)
      for (j=1;j<=1;j++)
        for (k=1;k<=n;k++)
          tmp[i][j]+=b[i][k]*r[k][j];
    for (i=1;i<=n;i++)
      for (j=1;j<=1;j++)
        for (k=1;k<=n;k++)
          tmp2[i][j]+=a[i][k]*tmp[k][j];
    for (i=1;i<=n;i++)
      for (j=1;j<=1;j++)
        for (k=1;k<=n;k++)
          tmp3[i][j]+=c[i][k]*r[k][j];
	bool flag=true;
    for (i=1;i<=n;i++)
      if (tmp2[i][1]!=tmp3[i][1])
      {
        flag=false;
        break;
	  }
	if (flag)
	  printf("YES\n");
	else
	  printf("NO\n");
  }
  return 0;
}

