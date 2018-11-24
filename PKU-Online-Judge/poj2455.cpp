#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
#define MN 203
using namespace std;

int cur[MN],dis[MN];
int c[40003][3];
bool vis[MN];
struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int T;

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
  q.push(1);
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
  vis[1]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

int dfs(int u,int a)
{
  int flow=0,f;
  if (u==T||a==0) return a;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      a-=f;
      flow+=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  int n,i,j,k,m,t;
  //freopen("2455.in","r",stdin);
  //freopen("2455.out","w",stdout);
  scanf("%d%d%d",&n,&m,&t);
  es.clear();
  memset(c,0,sizeof(c));
  T=n;
  for (i=0;i<MN;i++)
    g[i].clear();
  int l=1000000,r=0;//10000001;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&c[i][0],&c[i][1],&c[i][2]);
    l=min(l,c[i][2]);
    r=max(r,c[i][2]); 
  } 
  while(l<r)
  {
    es.clear();
    for (i=0;i<MN;i++) g[i].clear();
    int mid=l+((r-l)>>1);
    for (i=1;i<=m;i++)
      if (c[i][2]<=mid)
      {
        addedge(c[i][0],c[i][1],1);
        addedge(c[i][1],c[i][0],1);
      }
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(1,INF);
    }
    if (ans>=t) r=mid;
      else l=mid+1;
  }
  printf("%d\n",l);
  return 0;
} 
