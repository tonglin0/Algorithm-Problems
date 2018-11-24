#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define lint long long
#define eps 1e-8
#define INF (int)1e9
using namespace std;

int a[100003][102];
char ch;
int r[100003][2];
int tmp1[100003][2];
int tmp2[100003][2];

void read(int &x)
{
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch<='9'&&ch>='0') x=x*10+ch-'0';
}

int main()
{
  freopen("3243.in","r",stdin);
  freopen("3243.out","w",stdout);
  int n,m,i,j,K,k;
  int d;
  scanf("%d%d%d",&n,&d,&K);
  for (i=1;i<=n;i++)
    for (j=1;j<=d;j++)
      read(a[i][j]),a[i][j]%=K;
  if (K==2)
  {
  	for (i=1;i<=n;i++)
  	  r[i][1]=0;
  	for (j=1;j<=d;j++)
  	  for (i=1;i<=n;i++)
  	    r[j][1]=(r[j][1]+a[i][j])&1;
	for (i=1;i<=n;i++)
  	  for (j=1;j<=1;j++)
  	    for (k=1;k<=d;k++)
  	      tmp1[i][j]=(tmp1[i][j]+a[i][k]*r[k][j])&1;
  	for (i=1;i<=n;i++)
  	{
  	  for (j=1;j<=d;j++)
  	    tmp2[i][1]=(tmp2[i][1]+a[i][j]*a[i][j])&1;
	  tmp2[i][1]=(tmp2[i][1]+n-1)&1;
    }
    for (i=1;i<=n;i++)
      if (tmp1[i][1]!=tmp2[i][1])
      {
        for (j=1;j<=n;j++)
        {
          if (i==j) continue;
          int s=0;
          for (k=1;k<=d;k++)
            s=(s+a[i][k]*a[j][k])&1;
          if (s==0)
          {
            printf("%d %d\n",min(i,j),max(i,j));
            return 0;
		  }
		}
	  }
	printf("-1 -1\n");
	return 0;
  }
  else
  {
    
  }
  return 0;
}

