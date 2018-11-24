#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF (int)1e9
using namespace std;

int st[1<<17];
int v[20];
struct point{
	double x,y;
};
point p[17];
int top;
int n;
bool vis[1<<17];
int ans1[1<<17];
int f[20][1<<17];
int dis[20][20];
bool vs[20][1<<17];

void dfs(int k,int m,int s)
{
  if (k==n)
  {
    if (!vis[s])
    {
      vis[s]=true;
      st[++top]=s;
	}
	return ;
  }
  if (m>=v[k])
    dfs(k+1,m-v[k],s|(1<<k));
  dfs(k+1,m,s);
}

int TSP(int u,int s)
{
  if (vs[u][s])
    return f[u][s];
  vs[u][s]=true;
  if (s==0)
    return f[u][s]=dis[u][0];
  for (int i=0;i<n;i++)
    if (s&(1<<i))
      f[u][s]=min(f[u][s],TSP(i,s-(1<<i))+dis[u][i]);
  return f[u][s];
}

int main()
{
  freopen("4281.in","r",stdin);
  freopen("4281.out","w",stdout);
  int i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
	bool flag=true;
    for (i=0;i<n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    for (i=0;i<n;i++)
    {
      scanf("%d",&v[i]);
      if (v[i]>m)
        flag=false;
	}
    if (!flag)
    {
      printf("-1 -1\n");
      continue;
	}
	memset(st,0,sizeof(st));
    top=0;
    memset(vis,0,sizeof(vis));
    dfs(1,m,0);
    for (i=0;i<(1<<n);i++)
      ans1[i]=INF;
    ans1[0]=0;
    for (i=0;i<(1<<n);i+=2)
      for (j=1;j<=top;j++)
        if ((i&st[j])==0)
          ans1[i|st[j]]=min(ans1[i|st[j]],ans1[i]+1);
	printf("%d ",ans1[(1<<n)-2]);
	for (i=0;i<n;i++)
	  for (j=0;j<n;j++)
	    dis[i][j]=ceil(sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)));
	memset(vs,0,sizeof(vs));
	memset(f,60,sizeof(f));
	for (i=1;i<=top;i++)
	  f[0][st[i]]=TSP(0,st[i]);
	for (i=0;i<(1<<n);i++)
	  ans1[i]=INF;
	ans1[0]=0;
	for (i=1;i<=top;i++)
	  ans1[st[i]]=f[0][st[i]];
	for (i=0;i<(1<<n);i+=2)
	  for (j=1;j<=top;j++)
	    if ((i&st[j])==0)
	      ans1[i|st[j]]=min(ans1[i|st[j]],ans1[i]+ans1[st[j]]);
	printf("%d\n",ans1[(1<<n)-2]);
  }
  return 0;
}
