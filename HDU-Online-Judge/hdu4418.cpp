#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

double p[209];
double a[209][209];
int id[209];
int top;
int S,T;
int n,m;

void bfs(int u)
{
  queue<int> q;
  q.push(u);
  while(!q.empty())
  {
    int v=q.front();q.pop();
    if (id[v])
      continue;
    id[v]=++top;
    for (int i=1;i<=m;i++)
    {
      if (p[i]<eps)
        continue;
	  int j=(v+i)%n;
      if (!id[j])
        q.push(j);
	}
  }
}

void build()
{
  for (int i=0;i<n;i++)
  {
    if (!id[i])
      continue;
    if (i==T||n-i==T)
    {
      a[id[i]][id[i]]=1;
      a[id[i]][top+1]=0;
      continue;
	}
	a[id[i]][id[i]]=1;
	for (int j=1;j<=m;j++)
	{
	  if (p[j]<eps)
	    continue;
	  int v=(i+j)%n;
	  if (!id[v])
	    continue;
	  a[id[i]][id[v]]-=p[j];
	  a[id[i]][top+1]+=j*p[j];
	}
  }
}

void gause(int n,int m)
{
  int i=1,j=1,r,u,k;
  while(i<=n&&j<=m)
  {
    r=i;
    for (k=i;k<=n;k++)
      if (fabs(a[k][j])>eps)
      {
        r=k;
        break;
	  }
	if (fabs(a[r][j])>eps)
	{
	  if (r!=i)
	    for (k=j;k<=m+1;k++)
	      swap(a[i][k],a[r][k]);
	  for (u=1;u<=n;u++)
	    if (u!=i&&fabs(a[u][j])>eps)
	    {
	      double b1=a[u][j],b2=a[i][j];
		  for (k=m+1;k>=1;k--)
	        a[u][k]-=b1/b2*a[i][k];
	    }
	  i++;
	}
	j++;
  }
  for (k=i;k<=n;k++)
    if (fabs(a[k][m+1])>eps)
    {
      printf("Impossible !\n");
      return ;
	}
  for (i=n;i>=1;i--)
    a[i][m+1]/=a[i][i];
  printf("%.2lf\n",a[id[S]][m+1]);
}

int main()
{
  freopen("4418.in","r",stdin);
  freopen("4418.out","w",stdout);
  int ca,i,j,k,d;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d%d%d%d",&n,&m,&T,&S,&d);
    for (i=1;i<=m;i++)
    {
      scanf("%lf",&p[i]);
      p[i]/=100.0;
	}
	if (S==T)
	{
	  printf("0.00\n");
	  continue;
	}
	n=2*(n-1);
	if (d==1)
	  S=(n-S);
	memset(id,0,sizeof(id));
	top=0;
	bfs(S);
	if ((!id[T])&&(!id[(n-T)%n]))
	{
	  printf("Impossible !\n");
	  continue;
	}
	memset(a,0,sizeof(a));
	build();
	gause(top,top);
  }
  return 0;
}

