#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define MN 203
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int po[MN][2];
int cur[MN],dis[MN];
bool vis[MN];
int T;

int sqr(int a)
{
  return a*a;
}

double dist(int x1,int y1,int x2,int y2)
{
  return sqrt((double)sqr(x2-x1)+(double)sqr(y2-y1));
}

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
      if (e.c>e.f&&!vis[e.to])
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
  for(int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    cur[u]=i;
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
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
  int TC;
  //freopen("3498.in","r",stdin);
  //freopen("3498.out","w",stdout);
  scanf("%d",&TC);
  while(TC--)
  {
    int n,i,j,k,m;
    int N=0;
    double d;
    memset(po,0,sizeof(po));
    es.clear();
    for (i=0;i<MN;i++) g[i].clear();
    scanf("%d%lf",&n,&d);
    for (i=1;i<=n;i++)
    {
      int x,y,ni,mi;
      scanf("%d%d%d%d",&x,&y,&ni,&mi);
      N+=ni;
      addedge(0,i,ni);
      po[i][0]=x;
      po[i][1]=y;
      addedge(i,i+n,mi);
      for (j=1;j<i;j++)
        if (dist(po[i][0],po[i][1],po[j][0],po[j][1])<=d)
        {
          addedge(j+n,i,INF);
          addedge(i+n,j,INF);
        }
    }
    T=1;//n+n+1;
    //addedge(1,T,INF);
    int ans=0,s=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(0,INF);
    }
    if (ans>=N)
    {
      s++;
      printf("%d ",0);
    }
    //printf("ans=%d\n",ans);
    for (i=2;i<=n;i++)
    {
      m=es.size();
      for (j=0;j<m;j++)
        es[j].f=0;
      //es[m-2].from=i;
      //es[m-1].to=i;
      T=i;
      ans=0;
      while(bfs())
      {
        memset(cur,0,sizeof(cur));
        ans+=dfs(0,INF);
      }
      if (ans>=N)
      {
        s++;
        printf("%d ",i-1);
      }
      //printf("ans=%d\n",ans);
    }
    if (s==0) printf("-1\n");
      else printf("\n");
  }
  return 0;
}
