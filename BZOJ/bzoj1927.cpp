#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 1605
using namespace std;

int S,T,cost=0;
struct edge{
	int from,to,c,f,cost;
};
int dis[MN];
int p[MN],a[MN];
int flow=0;
bool vis[MN],ins[MN];
vector<edge> es;
vector<int> g[MN];

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
    cost+=dis[S]*a;
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

bool relabel()
{
  int t=INF;
  for (int i=0;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (!vis[e.to]&&e.c>e.f)
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
  freopen("1927.in","r",stdin);
  freopen("1927.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  S=0;T=n+n+1;
  for (i=1;i<=n;i++)
  {
    int d;
    scanf("%d",&d);
    addedge(S,i,1,d);
  }
  for (i=1;i<=m;i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    if (u>v)
      swap(u,v);
    addedge(u+n,v,1,w);
  }
  for (i=1;i<=n;i++)
    addedge(i,T,1,0);
  for (i=1;i<=n;i++)
    addedge(S,i+n,1,0);
  /*prepare();
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(relabel());*/
  while(spfa());
  printf("%d\n",cost);
  //printf("%.6lf\n",clock()/(double)CLOCKS_PER_SEC);
  return 0;
}

