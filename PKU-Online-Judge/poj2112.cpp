#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define MN 353
#define INF (int)1e8
using namespace std;

int dis[MN],cur[MN],map[MN][MN];
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
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  queue<int> q;
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
  freopen("2112.in","r",stdin);
  freopen("2112.out","w",stdout);
  int l=INF,r=-INF,n,i,j,m,kk;
  scanf("%d%d%d",&m,&n,&kk);
  memset(map,0,sizeof(map));
  int N=m+n;
  for (i=1;i<=N;i++)
  {
    for (j=1;j<=N;j++)
    {
      scanf("%d",&map[i][j]);
      //if (map[i][j]!=0){l=min(l,map[i][j]);r=max(r,map[i][j]);}
      if (map[i][j]==0) map[i][j]=INF;
    }
  }
  int k;
  for (k=1;k<=N;k++)
    for (i=1;i<=N;i++)
      for (j=1;j<=N;j++)
        map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
  T=N+1;
  for (i=1;i<=N;i++)
    for (j=1;j<=N;j++)
      if (map[i][j]!=INF)
      {
        l=min(l,map[i][j]);
        r=max(r,map[i][j]);
      }
  while(l<r)
  {
    es.clear();
    for (i=0;i<=T;i++)
      g[i].clear();
    int mid=l+((r-l)>>1);
    for (i=1;i<=m;i++)
      for (j=m+1;j<=N;j++)
        if (map[i][j]<=mid)
          addedge(i,j,INF);
    for (i=1;i<=m;i++) 
      addedge(0,i,kk);
    for (i=m+1;i<=N;i++)
      addedge(i,T,1);
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,1);
    }
    if (ans==n) r=mid;
      else l=mid+1;
  }
  printf("%d\n",l);
  return 0;
}
