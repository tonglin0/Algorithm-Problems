#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lint long long
using namespace std;

int a[109][109];
int b[109][109];

lint gause(int n,int m)
{
  int i=1,j=1,k,r;
  while(i<=n&&j<=m)
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
	    for (k=0;k<=m+1;k++)
	      swap(a[i][k],a[r][k]);
	  for (k=i+1;k<=n;k++)
	    if (a[k][j])
	      for (int u=i;u<=m+1;u++)
	        a[k][u]^=a[i][u];
	  i++;
	}
	j++;
  }
  int tmp=i-1;
  for (i=1;i<=n;i++)
  {
    int t=0;
    for (j=1;j<=m;j++)
      t|=a[i][j];
    if ((t==0)&&(a[i][m+1]>0))
      return 0;
  }
  return 1LL<<(m-tmp);
}

int main()
{
  freopen("3364.in","r",stdin);
  freopen("3364.out","w",stdout);
  int ii,n,i,j,k,m,T;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&k);
      while(k--)
      {
        scanf("%d",&j);
        a[j][i]=1;
	  }
	}
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	    b[i][j]=a[i][j];
	int q;
	scanf("%d",&q);
	printf("Case %d:\n",ii);
	while(q--)
	{
	  for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++)
	      a[i][j]=b[i][j];
	  for (i=1;i<=n;i++)
	    scanf("%d",&a[i][m+1]);
	  lint ans=gause(n,m);
	  printf("%I64d\n",ans);
	}
  }
  return 0;
}
