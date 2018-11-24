#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int ans;
int a[459][459];
int anss[459];
int x[459];
int sz;
char st[100];

int cal()
{
  int i,n=sz,cnt=0,j,k=0;
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
	  cnt++;
  }
  return cnt;
}

void dfs(int k,int cnt)
{
  if (cnt==0)
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
  int i=1,j=1,jj=1,k,u,r;
  while(i<=n&&j<=m&&jj<=m)
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
	    for (k=1;k<=m+1;k++)
	      swap(a[r][k],a[i][k]);
	  for (u=1;u<=n;u++)
	    if (u!=i&&a[u][j])
	      for (k=1;k<=m+1;k++)
	        a[u][k]^=a[i][k];
	  i++;
	  j++;
	}
	else
	{
	  int val=m-jj+j;
	  for (k=1;k<=n;k++)
	    swap(a[j][k],a[val][k]);
	}
	jj++;
  }
  for (k=i;k<=n;k++)
    if (a[k][m+1])
    {
      ans=-1;
      return ;
	}
  r=i-1;
  dfs(1,m-r);
}

int main()
{
  freopen("1681.in","r",stdin);
  freopen("1681.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    memset(a,0,sizeof(a));
	scanf("%d",&n);
	sz=0;
	ans=(int)1e9;
	k=n*n+1;
	for (i=1;i<=n;i++)
	{
      scanf("%s",st);
      for (j=0;j<n;j++)
        if (st[j]=='y')
          a[++sz][k]=0;
        else
          a[++sz][k]=1;
	}
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        int t=(i-1)*n+j;
        for (int ii=1;ii<=n;ii++)
          for (int jj=1;jj<=n;jj++)
            if (abs(i-ii)+abs(j-jj)<=1)
              a[n*(ii-1)+jj][t]=1;
	  }
	gause(sz,sz);
	if (ans==-1)
	  printf("inf\n");
	else
	  printf("%d\n",ans);
  }
  return 0;
}
