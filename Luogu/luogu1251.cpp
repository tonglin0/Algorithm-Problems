#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#define INF (int)1e9
#define MN 4008
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int dis[MN],c[MN];
bool vis[MN];
int S,T;
long long cost=0;

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

int aug(int u,int a)
{
  if (u==T)
  {
    cost+=(long long)dis[S]*a;
    return a;
  }
  int A=a;
  vis[u]=true;
  for (int i=0;i<g[u].size();i++)
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
  for (int i=0;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (e.c>e.f&&!vis[e.to])
          t=min(t,dis[e.to]+e.cost-dis[i]);
      }
  if (t==INF) return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

int main()
{
  freopen("1251.in","r",stdin);
  freopen("1251.out","w",stdout);
  int n,i,j,k,m,p,q,s,t,f;
  scanf("%d",&n);
  memset(c,0,sizeof(c));
  S=0;T=n+n+1;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&k);
    c[i]=k;
  } 
  scanf("%d%d%d%d%d",&m,&p,&f,&q,&s);
  for (i=1;i<=n;i++)
  {
    addedge(S,i,c[i],m);
    addedge(i,T,c[i],0);
    addedge(S,i+n,c[i],0);
    if (i+1<=n)
      addedge(i+n,i+n+1,INF,0);
    if (i+p<=n)
      addedge(i+n,i+p,INF,f);
    if (i+q<=n)
      addedge(i+n,i+q,INF,s);
  }
  do
    do
      memset(vis,0,sizeof(vis));
    while (aug(S,INF));
  while(modlabel());
  cout<<cost<<endl;
  return 0;
}
