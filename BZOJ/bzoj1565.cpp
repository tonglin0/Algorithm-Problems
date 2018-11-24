#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 605
using namespace std;

int ind[MN];
int a[35][35];
vector<int> f[MN];
bool ins[MN];
int S,T;
int dis[MN],cur[MN];
bool vis[MN];
struct edge{
	int from,to,c,f;
};
vector<edge> es;
vector<int> g[MN];

void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  queue<int> q;
  memset(vis,0,sizeof(vis));
  dis[S]=0;
  q.push(S);
  vis[S]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
	  }
	}
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0)
    return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}

int main()
{
  freopen("1565.in","r",stdin);
  freopen("1565.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      scanf("%d",&a[i][j]);
      int u,w;
      int id=(i-1)*m+j;
      scanf("%d",&w);
      int x,y;
      while(w--)
      {
        scanf("%d%d",&x,&y);
        x++;y++;
        u=(x-1)*m+y;
        f[id].push_back(u);
        ind[u]++;
	  }
	  if (j>1)
	  {
	    f[id].push_back(id-1);
	    ind[id-1]++;
	  }
	}
  queue<int> q;
  for (i=1;i<=n*m;i++)
    if (ind[i]==0)
    {
      ins[i]=true;
      q.push(i);
	}
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (i=0;i<f[u].size();i++)
    {
      int v=f[u][i];
      if (--ind[v]==0)
      {
        ins[v]=true;
        q.push(v);
	  }
	}
  }
  int ans=0;
  S=0;T=n*m+1;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      int u=(i-1)*m+j;
      if (!ins[u]) continue;
      for (k=0;k<f[u].size();k++)
        if (ins[f[u][k]])
          addedge(f[u][k],u,INF);
	  if (a[i][j]>0)
	  {
	    addedge(S,u,a[i][j]);
	    ans+=a[i][j];
	  }
	  else
	    addedge(u,T,-a[i][j]);
	}
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans-=dfs(S,INF);
  }
  printf("%d\n",ans);
  return 0;
}

