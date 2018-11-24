#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define MN 6006
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int s[MN],win[MN],lose[MN],c[MN],d[MN],si[MN];
int S,T;//,cost=0;
long long cost=0;
bool ins[MN],vis[MN];
int p[MN],a[MN],dis[MN];

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

void prepare()
{
  memset(ins,0,sizeof(ins));
  for (int i=S;i<=T;i++)
    dis[i]=INF;
  dis[T]=0;
  ins[T]=true;
  queue<int> q;
  q.push(T);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (es[g[u][i]^1].c>es[g[u][i]^1].f&&dis[e.to]>dis[u]+es[g[u][i]^1].cost)
      {
        dis[e.to]=dis[u]+es[g[u][i]^1].cost;
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
}

bool spfa()
{
  memset(dis,60,sizeof(dis));
  memset(ins,0,sizeof(ins));
  queue<int> q;
  memset(a,0,sizeof(a));
  memset(p,0,sizeof(p));
  a[S]=INF;
  dis[S]=0;
  ins[S]=true;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[e.to]>dis[u]+e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
        if(!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);              
        }
      }
    }
  }
  if (dis[T]==dis[MN-2]) return false;
  cost+=(long long)a[T]*dis[T];
  int u=T;
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int aug(int u,int a)
{
  if (u==T)
  {
    cost+=(long long)dis[S]*a;
    return a;
  }
  vis[u]=true;
  int A=a;
  for(int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!vis[e.to]&&dis[u]==dis[e.to]+e.cost)
    {
      int f=aug(e.to,min(A,e.c-e.f));
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      A-=f;
      if (A==0) return a;
    }
  }
  return a-A;
}

bool modlabel()
{
  int t=INF;
  for (int i=S;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (!vis[e.to]&&e.c>e.f)
          t=min(t,dis[e.to]+e.cost-dis[i]);
      }
  if (t==INF) return false;
  for (int i=S;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

int main()
{
  //freopen("1449.in","r",stdin);
  //freopen("1449.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(win,0,sizeof(win));
  memset(lose,0,sizeof(lose));
  memset(c,0,sizeof(c));
  memset(d,0,sizeof(d));
  memset(si,0,sizeof(si));
  S=0;
  T=m+n+1;
  for (i=1;i<=n;i++)
    {scanf("%d%d%d%d",&win[i],&lose[i],&c[i],&d[i]);si[i]=win[i]+lose[i];}
  memset(s,0,sizeof(s));
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    si[u]++;
    si[v]++;
    addedge(S,i,1,0);
    addedge(i,u+m,1,0);
    addedge(i,v+m,1,0);
  }
  for (i=1;i<=n;i++)
  {
    int u=i+m;
    for (j=win[i]+1;j<=si[i]-lose[i];j++)
      addedge(u,T,1,(c[i]+d[i])*(2*j-1)-2*d[i]*si[i]);
  }
  //while(spfa());
  memset(dis,0,sizeof(dis));
  prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while (modlabel());
  for (i=1;i<=n;i++)
    s[i]=c[i]*win[i]*win[i]+d[i]*(si[i]-win[i])*(si[i]-win[i]);
  for (i=1;i<=n;i++)
    cost+=s[i];
  printf("%lld\n",cost);
  return 0;
}
