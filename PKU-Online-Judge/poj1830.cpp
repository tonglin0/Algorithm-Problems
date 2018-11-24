#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[62][63];
int x[50];
int ans;

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
	  for (u=i+1;u<=n;u++)
	    if (a[u][j])
	      for (k=j;k<=m+1;k++)
	        a[u][k]^=a[i][k];
	  i++;
	}
	j++;
  }/*
  for (k=i;k<=n;k++)
    if (a[k][m+1])
    {
      ans=-1;
      return ;
	}*/
  for  (j=1;j<=n;j++)
  {
    int t=0;
    for (k=1;k<=m;k++)
      t|=a[j][k];
    if ((!t)&&(a[j][m+1]))
    {
      ans=-1;
      return ;
	}
  }
  i--;
  ans=m-i;
}

int main()
{
  freopen("1830.in","r",stdin);
  freopen("1830.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    ans=(int)1e9;
    for (i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i][n+1]);
      a[i][n+1]^=x[i];
    }
    int u,v;
    while(scanf("%d%d",&u,&v)==2&&(u+v))
    {
      //a[u][v]=1;
      a[v][u]=1;
	}
	for(i=1;i<=n;i++)
	  a[i][i]=1; 
	gause(n,n);
	if (ans==-1)
	  printf("Oh,it's impossible~!!\n");
	else
	  printf("%d\n",1<<ans);
  }
  return 0;  
}
