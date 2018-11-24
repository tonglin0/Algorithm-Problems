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
using namespace std;

struct point{int x,y;point(int x=0,int y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,int b){return vec(a.x*b,a.y*b);}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double dist(point a,point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
point a[203];
int tms[203],dr[203];
point b[203];
point c[203];
int tr[203];
int k;

struct edge{
	int from,to,c,f;
};
int S,T;
vector<edge> es;
vector<int> g[409];
int dis[409],cur[409];
bool vis[409];
double psdist(point c,point b,point a)
{
  if (dcmp(dot(c-b,a-b))<=0)
    return dist(b,c);
  if (dcmp(dot(c-a,b-a))<=0)
    return dist(a,c);
  return fabs((double)cross(b-a,c-a))/dist(a,b);
}

bool hefa(int x,int y)
{
  if ((a[x].x-b[y].x)*(a[x].x-b[y].x)+(a[x].y-b[y].y)*(a[x].y-b[y].y)>dr[x]*dr[x])
    return false;
  for (int i=1;i<=k;i++)
    if (dcmp(psdist(c[i],a[x],b[y])-tr[i])<0)
      return false;
  return true;
}

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
  vis[S]=true;
  queue<int> q;
  q.push(S);
  dis[S]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
      {
        vis[e.to]=true;
        q.push(e.to);
        dis[e.to]=dis[u]+1;
	  }
	}
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0)
    return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
    edge e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}

int main()
{
  freopen("1822.in","r",stdin);
  freopen("1822.out","w",stdout);
  int ca,n,i,j,m,ii=0;
  scanf("%d%d%d",&n,&m,&k);
  int tmp=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d%d%d",&a[i].x,&a[i].y,&dr[i],&tms[i]);
    tmp=max(tmp,tms[i]);
  }
  for (i=1;i<=m;i++)
    scanf("%d%d",&b[i].x,&b[i].y);
  for (i=1;i<=k;i++)
    scanf("%d%d%d",&c[i].x,&c[i].y,&tr[i]);
  S=0;T=n+m+1;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      if (hefa(i,j))
        addedge(i,j+n,1);
  for (i=1;i<=m;i++)
    addedge(i+n,T,1);
  int l=0,r=tmp*m+1;
  int mid=(l+r)>>1;
  for (i=1;i<=n;i++)
    addedge(S,i,mid/tms[i]+1);
  while(l<r)
  {
    mid=l+r>>1;
    for (i=0;i<es.size();i++)
    {
      es[i].f=0;
      if (es[i].from==S)
        es[i].c=mid/tms[es[i].to]+1;
	}
    int ans=0;
	while(bfs())
	{
      memset(cur,0,sizeof(cur));
      ans+=dfs(S,INF);
	}
	if (ans==m)
	  r=mid;
	else
	  l=mid+1;
  }
  if (l==tmp*m+1)
    printf("-1\n");
  else
    printf("%d\n",l);
  return 0;
}

