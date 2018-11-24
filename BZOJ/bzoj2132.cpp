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
#define MN 10009
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int a[103][103],mk[103][103],b[103][103],c[103][103];


struct edge{
	int from,to,c,f;
};
vector<edge> es;
vector<int> g[MN];
int dis[MN],cur[MN];
bool vis[MN];
int S,T;

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
  queue<int> q;
  q.push(S);
  for (int i=0;i<=T;i++)
    vis[i]=0;
  vis[S]=true;
  dis[S]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        vis[e.to]=true;
        dis[e.to]=dis[u]+1;
        q.push(e.to);
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

bool hefa(int x,int y,int n,int m)
{
  if (x<1||y<1)
    return false;
  if (x>n||y>m)
    return false;
  return true;
}

int main()
{
  freopen("2132.in","r",stdin);
  freopen("2132.out","w",stdout);
  int ca,n,m,i,j,k,ii=0;
  lint tot=0;
  scanf("%d%d",&n,&m);
  S=0;T=n*m+1;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      mk[i][j]=(i-1)*m+j;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
	  scanf("%d",&a[i][j]);
	  tot+=a[i][j];
	  if ((i+j)&1)
	    addedge(S,mk[i][j],a[i][j]);
	  else
	    addedge(mk[i][j],T,a[i][j]);
	}
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      scanf("%d",&b[i][j]);
      tot+=b[i][j];
      if ((i+j)&1)
        addedge(mk[i][j],T,b[i][j]);
      else
        addedge(S,mk[i][j],b[i][j]);
	}
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      scanf("%d",&c[i][j]);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      if (((i+j)&1)==0) continue;
      for (k=0;k<4;k++)
      {
        int x=i+dx[k];
        int y=j+dy[k];
        if (hefa(x,y,n,m))
        {
          addedge(mk[i][j],mk[x][y],c[i][j]+c[x][y]);
          addedge(mk[x][y],mk[i][j],c[i][j]+c[x][y]);
          tot+=(c[i][j]+c[x][y]);
		}
	  }
	}
  int ans=0;
  while(bfs())
  {
    for (i=0;i<=T;i++)
      cur[i]=0;
    ans+=dfs(S,INF);
  }
  printf("%lld\n",tot-ans);
  return 0;
  
}

