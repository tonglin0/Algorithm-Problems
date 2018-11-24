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
#define eps 1e-12
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 305
using namespace std;

int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double pq[MN];
double cost=0;
struct edge{
	int from,to,c,f;double cost;
};
vector<edge> es;
vector<int> g[MN];
int a[MN],p[MN];
double dis[MN];
bool ins[MN];
int S,T;

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

bool spfa()
{
  for (int i=0;i<=T;i++)
    dis[i]=INF,ins[i]=false;
  dis[S]=0;
  queue<int> q;
  q.push(S);
  a[S]=INF;
  p[S]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dcmp(dis[u]+e.cost-dis[e.to])<0)
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
  if (dcmp(dis[T]-INF)==0)
    return false;
  int u=T;
  cost+=a[T]*dis[T];
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
  freopen("2542.in","r",stdin);
  freopen("2542.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%lf",&pq[i]);
  int SS=0;
  S=n+1;T=n+2;
  addedge(S,SS,m,0);
  for (i=1;i<=n;i++)
  {
    int c;
    scanf("%d",&c);
    addedge(SS,i,c,-log(pq[i]));
  }
  for (i=1;i<=n;i++)
  {
    int op;
    scanf("%d",&op);
    if (op==1)
      addedge(i,T,INF,0);
  }
  int u,v,d;double w;
  while(scanf("%d%d",&u,&v)==2)
  {
    if (u==-1)
      break;
    scanf("%lf%d",&w,&d);
    addedge(u,v,d,-log(w));
    addedge(v,u,d,-log(w));
  }
  while(spfa());
  double ans=exp(-cost);
  char ss[30];
  if (dcmp(ans)==0)
  {
    printf("%.5lf\n",ans);
    return 0;
  }
  printf("0.");
  while(dcmp(ans-0.1)<0)
  {
    putchar('0');
    ans=ans*10;
  }
  sprintf(ss,"%.5lf\n",ans);
  i=2;
  j=1;
  while(j<=5)
  {
    putchar(ss[i]);
    i++;j++;
  }
  return 0;
}

