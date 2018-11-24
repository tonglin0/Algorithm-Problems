#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
using namespace std;

struct node{int u,v,w;};
struct edge{int from,to,c,f;};
vector<edge> es;
node p[40010];
bool vis[210];
int cur[210],dis[210];
vector<int> g[210];
int T;

void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;
  x.to=to;
  x.c=c;
  x.f=0;
  es.push_back(x);
  x.to=from;
  x.from=to;
  x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  queue<int> q;
  vis[0]=true;
  q.push(0);
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
  if (u==T||a==0) return a;
  int f,flow=0;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  freopen("1401.in","r",stdin);
  freopen("1401.out","w",stdout);
  int u,v,w,n,i,j,m,t,l,r;
  scanf("%d%d%d",&n,&m,&t);
  memset(p,0,sizeof(p));
  l=INF;r=-INF;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    p[i].u=u;p[i].v=v;p[i].w=w;
    l=min(l,w);
    r=max(r,w);
  }
  while(l<r)
  {
    int mid=l+((r-l)>>1);
    es.clear();
    for (i=0;i<210;i++) g[i].clear();
    for (i=1;i<=m;i++)
      if (p[i].w<=mid)
      {
        addedge(p[i].u,p[i].v,1);
        addedge(p[i].v,p[i].u,1);
      }
    int ans=0;
    T=n+1;
    addedge(0,1,INF);
    addedge(n,T,INF);
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    if (ans>=t) r=mid;
      else l=mid+1;
  }
  printf("%d\n",l);
  return 0;
}
