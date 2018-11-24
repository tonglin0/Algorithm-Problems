#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define MN 206
#define INF (int)1e9
using namespace std;

int in[MN][13],out[MN][13];
int dis[MN],cur[MN];
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
  memset(vis,0,sizeof(vis));
  memset(dis,0,sizeof(dis));
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
  if (u==T||a==0) return a;
  int flow=0,f;
  for(int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      e.f+=f;
      a-=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;                                                        
    }
  }
  return flow;
}

int main()
{
  int n,i,j,p,m;
  //freopen("3436.in","r",stdin);
  //freopen("3436.out","w",stdout);
  memset(in,0,sizeof(in));
  memset(out,0,sizeof(out));
  scanf("%d%d",&p,&n);
  T=n+n+1;
  for (i=1;i<=n;i++)
  {
    int u;
    scanf("%d",&u);
    addedge(i,i+n,u);
    bool is1=true,is0=true;
    for (j=1;j<=p;j++)
    {
      scanf("%d",&in[i][j]);
      if (in[i][j]==1) is0=false;
    }
    if (is0) addedge(0,i,INF);
    for (j=1;j<=p;j++)
    {
      scanf("%d",&out[i][j]);
      if (out[i][j]==0) is1=false;
    }
    if (is1) addedge(i+n,T,INF);
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j) continue;
      bool flag=true;
      for (int k=1;k<=p;k++)
        if ((in[j][k]==1&&out[i][k]!=1)||(in[j][k]==0&&out[i][k]==1))
        {
          flag=false;
          break;
        }
      if (flag) addedge(i+n,j,INF);
    }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(0,INF);
  }
  int s=0;
  for(i=1;i<es.size();i++)
    if (es[i].f>0&&es[i].from!=0&&es[i].to!=T&&!(es[i].to-n==es[i].from))
      s++;//printf("%d %d %d\n",es[i].from-n,es[i].to,es[i].f);
  printf("%d %d\n",ans,s);
  for(i=1;i<es.size();i++)
    if (es[i].f>0&&es[i].from!=0&&es[i].to!=T&&!(es[i].to-n==es[i].from))
      printf("%d %d %d\n",es[i].from-n,es[i].to,es[i].f);
  return 0;
}
