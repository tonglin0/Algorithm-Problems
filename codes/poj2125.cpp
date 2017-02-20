#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF (int)1e9
#define MN 1203
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int cur[MN],dis[MN],inc[MN],outc[MN];
bool vis[MN],mark[MN];
int T;

void addedge(int from,int to,int c)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;
  es.push_back(x);
  x.to=from;x.from=to;x.c=0;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bfs()
{
  queue<int> q;
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  q.push(0);
  vis[0]=true;
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
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    cur[u]=i;
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
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
  //freopen("2125.in","r",stdin);
  //freopen("2125.out","w",stdout);
  memset(inc,0,sizeof(inc));
  memset(outc,0,sizeof(outc));
  es.clear();
  int n,i,j,k,m;
  for (i=0;i<MN;i++) g[i].clear();
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&inc[i]);
  for (i=1;i<=n;i++)
    scanf("%d",&outc[i]);
  T=n+n+1;
  for (i=1;i<=n;i++)
  {
    addedge(0,i,outc[i]);
    addedge(i+n,T,inc[i]);
  }
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v+n,INF);
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  printf("%d\n",ans);
  memset(mark,0,sizeof(mark));
  queue<int> q;
  q.push(0);
  mark[0]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!mark[e.to])
      {
        mark[e.to]=true;
        q.push(e.to);
      }
    }
  }
  int s=0;
  for (i=0;i<es.size();i++)
    if (es[i].c!=0&&es[i].f==es[i].c&&mark[es[i].from]&&!mark[es[i].to])
      s++;
  printf("%d\n",s);
  for (i=0;i<es.size();i++)
    if (es[i].c!=0&&es[i].f==es[i].c&&mark[es[i].from]&&!mark[es[i].to])
      if (es[i].from==0)
        printf("%d -\n",es[i].to);
      else 
        printf("%d +\n",es[i].from-n);
  return 0;
}

