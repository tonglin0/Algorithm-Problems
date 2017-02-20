#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[150][150];
int p;
char st[150];

void gause(int n,int m)
{
  int i=1,j=1,k,r,u;
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
	    for (k=j;k<=m+1;k++)
	      swap(a[i][k],a[r][k]);
	  for (u=1;u<=n;u++)
	    if (u!=i&&a[u][j])
	    {
	      int b1=a[i][j];
	      int b2=a[u][j];
		  for (k=1;k<=m+1;k++)
	        a[u][k]=((a[u][k]*b1-a[i][k]*b2)%p+p)%p;
        }
	  i++;
	}
	j++;
  }
  for (i=1;i<=n;i++)
  {
    a[i][n+1]=(a[i][n+1]+p)%p;
    while(a[i][n+1]%a[i][i])
      a[i][n+1]+=p;
    a[i][n+1]/=a[i][i];
    a[i][n+1]=(a[i][n+1]%p+p)%p;
  }
  for (i=1;i<=n-1;i++)
    printf("%d ",a[i][n+1]);
  printf("%d\n",a[n][n+1]);
}

int main()
{
  freopen("2065.in","r",stdin);
  freopen("2065.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    memset(a,0,sizeof(a));
	scanf("%d",&p);
    scanf("%s",st);
    n=strlen(st);
    for (i=0;i<n;i++)
    {
      if (st[i]=='*')
        a[i+1][n+1]=0;
      else
        a[i+1][n+1]=st[i]-'a'+1;
	}
	for (i=1;i<=n;i++)
	{
	  k=1;
	  for (j=1;j<=n;j++)
	  {
	    a[i][j]=k;
	    k=k*i%p;
	  }
	}
	gause(n,n);
  }
  return 0;
}
