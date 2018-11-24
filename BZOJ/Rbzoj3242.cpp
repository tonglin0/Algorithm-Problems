#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define eps 1e-8
#define lint long long
#define INF (int)1e9
#define inf 1e16
#define MN 100009
using namespace std;

int es[MN][3];
struct edge{
	int v,id;
	double w;
};
vector<edge> g[MN];
int vis[MN];
bool ins[MN];
double dis[MN];

bool topo(int u,int fa)
{
  bool flag=true;
  vis[u]=-1;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i].v!=fa)
    {
      int v=g[u][i].v;
      if (vis[v]==-1)
      {
        ins[g[u][i].id]=true;
		return false;
	  }
      bool flag2=topo(v,u);
      if (flag&&(!flag2))
      {
        ins[g[u][i].id]=true;
        flag=false;
	  }
	}
  vis[u]=1;
  return flag;
}

void dfs_dis(int u,int fa)
{
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i].v;
    if (v==fa)
      continue;
    dis[v]=dis[u]+g[u][i].w;
    dfs_dis(v,u);
  }
}

int main()
{
  freopen("3242.in","r",stdin);
  freopen("3242.out","w",stdout);
  int n,m,i,j,k,ca;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d%d%d",&es[i][0],&es[i][1],&es[i][2]);
  for (i=1;i<=n;i++)
  {
    int u=es[i][0],v=es[i][1],w=es[i][2];
    edge e;
    e.v=v;e.w=w;e.id=i;
    g[u].push_back(e);
    e.v=u;
    g[v].push_back(e);
  }
  memset(ins,0,sizeof(ins));
  memset(vis,0,sizeof(vis));
  topo(1,0);
  double ans=inf;
  for (int ii=1;ii<=n;ii++)
    if (ins[ii])
    {
      for (i=0;i<=n;i++)
        g[i].clear();
      for (i=1;i<=n;i++)
        if (i!=ii)
        {
          int u=es[i][0];
          int v=es[i][1];
          double w=es[i][2];
          edge e;e.v=v;e.w=w;
          g[u].push_back(e);
          e.v=u;
          g[v].push_back(e);
		}
	  dis[1]=0;
	  dfs_dis(1,0);
	  k=2;
	  for (i=3;i<=n;i++)
	    if (dis[i]>dis[k])
	      k=i;
	  dis[k]=0;
	  dfs_dis(k,0);
	  double ts=0;
	  for (i=1;i<=n;i++)
	    if (i!=k)
	      if (dis[i]>ts)
	        ts=dis[i];
	  if (ts<ans)
	    ans=ts;
	}
  printf("%.1lf\n",ans/2.0);
  return 0;
}


