#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

char s1[10],s2[10];
int a[309][309];
int ans[309];

int day(char *s)
{
  if (s[0]=='M')
    return 1;
  else if (strcmp(s,"TUE")==0)
    return 2;
  else if (s[0]=='W')
    return 3;
  else if (s[0]=='F')
    return 5;
  else if (strcmp(s,"SAT")==0)
    return 6;
  else if (strcmp(s,"SUN")==0)
    return 7;
  else 
    return 4;
}

void gause(int n,int m)
{
  int i=1,j=1,k,u,r;
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
	      int b2=a[u][j];
	      for (k=m+1;k>=1;k--)
	        a[u][k]=((a[u][k]*a[i][j]-a[i][k]*b2)%7+7)%7;
	    }
	  i++;
	}
	j++;
  }
  for (k=i;k<=n;k++)
    if (a[k][m+1])
    {
      printf("Inconsistent data.\n");
      return ;
	}
  i--;
  if (m-i>0)
  {
    printf("Multiple solutions.\n");
    return ;
  }
  memset(ans,0,sizeof(ans));
  for (i=m;i>=1;i--)
  {
  	a[i][m+1]%=7;
    while(a[i][m+1]%a[i][i]!=0)
      a[i][m+1]+=7;
    ans[i]=(a[i][m+1]/a[i][i]%7+7)%7;
    if (ans[i]<3)
      ans[i]+=7;
  }
  for (i=1;i<=m-1;i++)
    printf("%d ",ans[i]);
  printf("%d\n",ans[m]);
}

int main()
{
  freopen("2947.in","r",stdin);
  freopen("2947.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2&&(n+m))
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=m;i++)
    {
      scanf("%d%s%s",&k,s1,s2);
      a[i][n+1]=(day(s2)-day(s1)+8)%7;
      while(k--)
      {
        int t;
        scanf("%d",&t);
        a[i][t]=(a[i][t]+1)%7;
	  }
	}
    gause(m,n);
  }
  return 0;
}
