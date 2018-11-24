#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cstring>
#define INF (int)1e9
#define MN 604
#define CR 100000
using namespace std;

struct edge{int from,to,c,f,cost;};
vector<edge> es;
vector<int> g[MN];
int dis[MN],p[MN],a[MN];
bool vis[MN],ins[MN];
int S,T,cost,flow=0;
vector<int> ss,ss2;

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
    cost+=a*dis[S];
    return a;
  }
  int A=a;
  for (int i=0;i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (!vis[e.to]&&e.c>e.f&&dis[u]==dis[e.to]+1)
    {
      int f=aug(e.to,min(A,e.c-e.f));
      e.f+=f;
      es[g[u][i]^1].f-=f;
      A-=f;
      if (A==0) return a;
    }
  }
  return a-A;
}

int find(int m,int x)
{
  for(int i=0;i<m;i++)
    if (ss[i]==x) return i;
  return INF;
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

bool spfa()
{
  memset(ins,0,sizeof(ins));
  memset(dis,60,sizeof(dis));
  memset(a,0,sizeof(a));
  memset(p,0,sizeof(p));
  queue<int> q;
  q.push(S);
  ins[S]=true;
  dis[S]=0;
  a[S]=INF;
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
        if (!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);
        }
      }
    }
  }
  if (dis[T]==dis[MN-1]) return false;
  int u=T;
  cost+=dis[T]*a[T];
  flow+=a[T];
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  int n,TC,j,i,m,k;
  //freopen("3680.in","r",stdin);
  //freopen("3680.out","w",stdout);
  scanf("%d",&TC);
  while(TC--)
  {
    es.clear();
    ss.clear();
    ss2.clear();
    for (i=0;i<MN;i++) g[i].clear();
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      //u++;
      int vu=find(ss.size(),u);
      if (INF==vu) 
      {
        ss.push_back(u);
        vu=ss.size()-1;
      }
      int vv=find(ss.size(),v);
      if (INF==vv)
      {
        ss.push_back(v);
        vv=ss.size()-1;
      }
      addedge(vu,vv,1,-w);
    }
    int size=ss.size();
    for (i=0;i<ss.size();i++)
      ss2.push_back(ss[i]);
    sort(ss2.begin(),ss2.end());
    T=size;
    for (i=0;i<ss.size()-1;i++)
    {
      int vu=find(ss.size(),ss2[i]);
      int vv=find(ss.size(),ss2[i+1]);
      addedge(vu,vv,m,0);
    }
    int vv=find(ss.size(),ss2[ss2.size()-1]);
    addedge(vv,T,m,0);
    S=find(ss.size(),ss2[0]);
    cost=flow=0;
    while(spfa());
    printf("%d\n",-cost);
  }
  return 0;
}
