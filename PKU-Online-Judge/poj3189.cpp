#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
#define MN 1020
using namespace std;

int cur[MN],p[50][MN],dis[MN];
bool vis[MN];
struct edge{int from,to,c,f;};
vector<edge> es;
int map[MN][24];
int c[24];
vector<int> g[MN];
int n,S,T;

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
  q.push(S);
  vis[S]=true;
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
  if(u==T||a==0) return a;
  int flow=0,f;
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

bool find(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i]])
    {
      vis[g[u][i]]=true;
      if (p[g[u][i]][0]<c[g[u][i]])
      {
        p[g[u][i]][++p[g[u][i]][0]]=u;
        return true;
      }
      else
      {
        for (int j=1;j<=c[g[u][i]];j++)
        {
          if (find(p[g[u][i]][j]))
          {
            p[g[u][i]][j]=u;
            return true;
          }
        }
      }
    }
  return false;
}

bool check(int l,int r)
{
  memset(p,0,sizeof(p));
  for (int i=0;i<MN;i++)
    g[i].clear();
  for (int i=1;i<=n;i++)
    for (int j=l;j<=r;j++)
      g[i].push_back(map[i][j]);
  for (int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    if (!find(i)) return false;
  }
  return true;
}

int main()
{
  //freopen("3189.in","r",stdin);
  //freopen("3189.out","w",stdout);
  memset(map,0,sizeof(map));
  int m,k,j,i;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      scanf("%d",&map[i][j]);
  memset(c,0,sizeof(c));
  for (i=1;i<=m;i++)
    scanf("%d",&c[i]);
  int l=1,r=1,minans=INF;
  T=m+n+1;
  S=0;
  while(r<=m)
  {
    /*es.clear();
    for (i=0;i<MN;i++) 
      g[i].clear();
    for (i=1;i<=m;i++)
      addedge(i+n,T,c[i]);
    for (i=1;i<=n;i++)
      addedge(S,i,1);
    for (i=1;i<=n;i++)
      for (j=l;j<=r;j++)
        addedge(i,map[i][j]+n,1);
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(S,INF);
    }*/
    if (check(l,r))
    {
      if (r-l+1<minans)
        minans=r-l+1;
      l++;//if (minans!=INF) l=r+1-minans+1;//minans
      //l++;
    }
    else 
      r++;//{  r++;if (minans!=INF) l=r+1-minans;}
  }
  printf("%d\n",minans);
  return 0;
}
