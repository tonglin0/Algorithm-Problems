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
#define MN 4003
using namespace std;

bool ans1[60003],ans2[60003];
struct edge{
	int from,to,c,f,id;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN];
bool vis[MN];
int S,T;
bool bs[MN],bt[MN];

void addedge(int from,int to,int c,int id)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.id=id;
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

void bfs1()
{
  queue<int> q;
  q.push(S);
  vis[S]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    bs[u]=true;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!bs[e.to])
      {
        bs[e.to]=true;
        q.push(e.to);
	  }
	}
  }
}

void bfs2()
{
  queue<int> q;
  q.push(T);
  vis[T]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    bt[u]=true;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (es[g[u][i]^1].c>es[g[u][i]^1].f&&!bt[e.to])
      {
        bt[e.to]=true;
        q.push(e.to);
	  }
	}
  }
}

int main()
{
  freopen("1797.in","r",stdin);
  freopen("1797.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d%d%d",&n,&m,&S,&T);
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w,i);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  bfs1();
  bfs2();
  memset(ans1,0,sizeof(ans1));
  memset(ans2,0,sizeof(ans2));
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
    {
      edge e=es[g[i][j]];
      if (e.c==0) continue;
	  if (e.c>e.f) continue;
      if (!((bs[e.from]&&bs[e.to])||(bt[e.from]&&bt[e.to])))
        ans1[e.id]=1;
      if ((bs[e.from]&&bt[e.to])||(bt[e.from]&&bs[e.to]))
        ans2[e.id]=1;
	}
  for (i=1;i<=m;i++)
    printf("%d %d\n",ans1[i],ans2[i]);
  return 0;
}

