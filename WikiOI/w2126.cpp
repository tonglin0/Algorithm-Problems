#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define eps 1e-8
#define INF (int)1e9
#define MN 404
using namespace std;

struct edge{int from,to,c,f;double cost;};
vector<edge> es;
vector<int> g[MN];
bool iscut[MN][MN];
int S,T;
double ans=0;
double dis[MN];
bool vis[MN];

double min(double a,double b)
{
  if (a<b) return a;
  return b;
}

void addedge(int from,int to,int c,double cost)
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
  if (u==T) //return ans+=a*dis[S],a;
  {
    ans+=a*dis[S];
    return a;
  }
  vis[u]=true;
  int A=a;
  for (int i=0;i<g[u].size();i++)
  {
    edge e=es[g[u][i]];
    if (e.c>e.f&&!vis[e.to]&&fabs(dis[u]-dis[e.to]-e.cost)<=eps)
    {
      int f=aug(e.to,min(e.c-e.f,A));
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
  double temp=INF;
  for (int i=0;i<=T;i++)
    if (vis[i])
      for (int j=0;j<g[i].size();j++)
      {
        edge e=es[g[i][j]];
        if(e.c>e.f&&!vis[e.to])
          temp=min(temp,dis[e.to]+e.cost-dis[i]);
      }
  if (fabs(temp-INF)<=eps) return false;
  for (int i=0;i<=T;i++)
    if (vis[i])
      dis[i]+=temp;
  return true;
}

int main()
{
  int n,m,i,j,k;
  //freopen("2126.in","r",stdin);
  //freopen("2126.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      scanf("%d",&k);
      addedge(i,n+j,1,-log(k)+10);
    }
  T=n+m+1;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&k);
    addedge(0,i,k,0);
  }
  for (i=1;i<=m;i++)
  {
    scanf("%d",&k);
    addedge(i+n,T,k,0);
  }
  S=0;
  memset(dis,0,sizeof(dis));
  do
    do memset(vis,0,sizeof(vis));
    while(aug(S,INF));
  while(modlabel());
  for (i=0;i<es.size();i++)
    if (es[i].f>0)
      iscut[es[i].from][es[i].to-n]=true;
  //printf("%.5lf\n",ans);
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
      if (iscut[i][j])
        printf("1");
      else 
        printf("0");
    printf("\n");
  }
  return 0;
}
