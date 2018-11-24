#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define eps 1e-8
#define INF (int)1e9
using namespace std;

double dis[404];
bool vis[404];
struct edge{int from,to,c,f;double cost;};
vector<edge> es;
vector<int> g[404];
int po[404][3];
int T,S;

int sqr(int a)
{
  return a*a;
}

double min(double a,double b)
{
  if (a<b) return a;
  return b;
}

double dist(int x1,int y1,int x2,int y2)
{
  return sqrt((double)(sqr(x1-x2)+sqr(y1-y2)));
}

void addedge(int from,int to,int c,double cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.cost=cost;x.f=0;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

int aug(int u,int a)
{
  if (u==T) return a;
  int A=a;
  vis[u]=true;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (!vis[e.to]&&e.c>e.f&&fabs(-dis[u]+dis[e.to]+e.cost)<=eps)
    {
      int f=aug(e.to,min(A,e.c-e.f));
      A-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (A==0) return a;
    }
  }
  return a-A;
}

bool modlabel()
{
  double t=INF;
  for (int i=0;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if (e.c>e.f&&!vis[e.to])
          t=min(t,dis[e.to]+e.cost-dis[i]);
      }
  if (fabs(t-INF)<=eps) return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=t;
  return true;
}

int main()
{
  //freopen("3565.in","r",stdin);
  //freopen("3565.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  memset(po,0,sizeof(po));
  es.clear();
  S=0;T=n+n+1;
  for (i=1;i<=n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    po[i][0]=x;
    po[i][1]=y;
    addedge(S,i,1,0);
  }
  for (i=1;i<=n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    addedge(i+n,T,1,0);
    for (j=1;j<=n;j++)
      addedge(j,i+n,1,dist(x,y,po[j][0],po[j][1]));
  }
  do 
    do
      memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(modlabel());
  for (i=1;i<=n;i++)
    for (j=0;j<g[i].size();j++)
      if (es[g[i][j]].c>0&&es[g[i][j]].f>0)
      {
        printf("%d\n",es[g[i][j]].to-n);
        break;
      }
  return 0;
}
