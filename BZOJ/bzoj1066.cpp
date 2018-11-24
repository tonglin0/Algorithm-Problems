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
#define INF (int)1e8
#define lint long long
#define llu unsigned long long
using namespace std;

struct edge{
	int from,to,c,f;
};
vector<edge> es;
vector<int> g[1000];
int dis[1000],cur[1000];
char st[30];
int S,T;
bool vis[30][30];

double dist(int x,int y,int i,int j)
{
  return sqrt((x-i)*(x-i)+(y-j)*(y-j)-0.001);
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
  bool vis[1001];
  memset(vis,0,sizeof(vis));
  queue<int> q;
  dis[S]=0;
  vis[S]=true;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (!vis[e.to]&&e.c>e.f)
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
  int f,flow=0;
  for (int i=0;i<g[u].size();i++)
  {
    cur[u]=i;
    edge e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      es[g[u][i]].f+=f;
      es[g[u][i]^1].f-=f;
      a-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}

int main()
{
  freopen("1066.in","r",stdin);
  freopen("1066.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  int d;
  scanf("%d%d%d",&n,&m,&d);
  int N=n*m;
  memset(vis,0,sizeof(vis));
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    for (j=0;j<m;j++)
      if (st[j]!='0')
      {
        addedge((i-1)*m+j+1,(i-1)*m+j+1+N,st[j]-'0');
        vis[i][j+1]=true;
      }
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      if (vis[i][j])
	  {
        int x,y;
        int id=(i-1)*m+j;
        for (x=1;x<=n;x++)
          for (y=1;y<=m;y++)
            if (vis[x][y]&&(x!=i||y!=j)&&dist(i,j,x,y)<=d)
              addedge(id+N,(x-1)*m+y,INF);
	  }
  int cnt=0;
  S=0;T=N+N+1;
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    for (j=0;j<m;j++)
      if (st[j]=='L')
        addedge(S,(i-1)*m+j+1,1),cnt++;
  }
  for (j=1;j<=min(n,d);j++)
    for (i=1;i<=m;i++)
      addedge((j-1)*m+i+N,T,INF);
  for (j=n;j>=max(1,n-d+1);j--)
    for (i=1;i<=m;i++)
      addedge((j-1)*m+i+N,T,INF);
  for (j=1;j<=min(d,m);j++)
    for (i=1;i<=n;i++)
      addedge((i-1)*m+j+N,T,INF);
  for (j=m;j>=max(m-d+1,1);j--)
    for (i=1;i<=n;i++)
      addedge((i-1)*m+j+N,T,INF);
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  printf("%d\n",cnt-ans);
  return 0;
}

