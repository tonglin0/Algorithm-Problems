#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 1009
using namespace std;

int q[5003][5];
struct edge{
	int from,to,c,f,cost;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN],p[MN],a[MN];
bool vis[MN],ins[MN];
int S,T;
int cost,flow;
int n;

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.cost=cost;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  for (int i=0;i<=n;i++)
    vis[i]=false;
  vis[S]=true;
  dis[S]=0;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
        q.push(e.to);
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

bool spfa()
{
  queue<int> q;
  for (int i=0;i<=n;i++)
    dis[i]=INF;
  dis[S]=0;
  p[S]=0;
  a[S]=INF;
  q.push(S);
  for (int i=0;i<=n;i++)
    ins[i]=false;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[u]+e.cost<dis[e.to])
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(e.c-e.f,a[u]);
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
		}
	  }
	}
  }
  if (dis[T]==INF)
    return false;
  int u=T;
  cost+=a[T]*dis[T];
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  freopen("1834.in","r",stdin);
  freopen("1834.out","w",stdout);
  int i,j,k,m,ii=0,ca;
  scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d%d",&q[i][1],&q[i][2],&q[i][3],&q[i][4]);
    addedge(q[i][1],q[i][2],q[i][3],0);
  }
  S=1;T=n;
  int ans=0;
  while(bfs())
  {
    for (i=0;i<=n;i++)
      cur[i]=0;
    ans+=dfs(S,INF);
  }
  for (i=0;i<es.size();i++)
    es[i].f=0;
  for (i=1;i<=m;i++)
    addedge(q[i][1],q[i][2],INF,q[i][4]);
  S=0;
  addedge(S,1,ans+k,0);
  cost=0;
  flow=0;
  while(spfa());
  printf("%d %d\n",ans,cost);
  return 0;
}

