#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define INF 1e9
#define MN 205
#define eps 1e-7
using namespace std;

struct edge{int from,to;double c,f;};
vector<edge> es;
vector<int> g[MN];
int c[MN],dis[MN],cur[MN],d[MN];
bool vis[MN];
int tot=0,S,T;

double min(double a,double b)
{
  if (a<b) return a;
  return b;
}

void addedge(int from,int to,double c)
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
  vis[S]=true;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c-e.f>eps&&!vis[e.to])
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

double dfs(int u,double a)
{
  if (u==T||a<eps) return a;
  double f,flow=0;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>eps)
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

void floodfill(int u)
{
  vis[u]=true;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c-e.f>eps&&!vis[e.to])
      floodfill(e.to);
  }
}

int main()
{
  //freopen("3155.in","r",stdin);
  //freopen("3155.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  if (m==0)
  {
    printf("1\n1\n");
    return 0;
  }
  S=0;T=n+1;
  int U=m;
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v,1);
    d[u]+=1;
    d[v]+=1;
    addedge(v,u,1);
  }
  for (i=1;i<=n;i++)
  {
    addedge(S,i,U);
    addedge(i,T,0);
  }
  double ans;
  double l=1.0/n;
  double r=(double)m;
  double eps2=1.0/(n*n);
  bool flag=true;
  while(flag)
  {
    double mid=l+((r-l)/2.0);
    for (i=m+m-1;i<es.size();i++)
      if (es[i].to==T)
        es[i].c=U+2*mid-d[es[i].from];
    for (i=0;i<es.size();i++)
      es[i].f=0;
    ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans=ans+dfs(S,INF);
    }
    if (U*n-ans>eps)
    {  
      l=mid;
      if (r-l<eps2) flag=false;
    }
    else
    {
      r=mid;
    }
  }
  //printf("%.4lf\n",l);
  memset(vis,0,sizeof(vis));
  memset(c,0,sizeof(c));
  floodfill(S);
  for (i=1;i<=n;i++)
    if (vis[i])
      c[tot++]=i;
  //sort(c,c+tot);
  printf("%d\n",tot);
  for (i=0;i<tot;i++)
    printf("%d\n",c[i]);
  return 0;
}
