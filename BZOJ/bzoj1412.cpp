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

int a[103][103];
int dis[MN],cur[MN];
bool vis[MN];
struct edge{
	int from,to,c,f;
};
vector<edge> es;
vector<int> g[MN];
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
  memset(vis,0,sizeof(vis));
  queue<int> q;
  q.push(S);
  vis[S]=true;
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
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
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
  freopen("1412.in","r",stdin);
  freopen("1412.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  S=0;T=n*m+1;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      scanf("%d",&a[i][j]);
    int id1=(i-1)*m+j;
    if (i>1)
    {
      if (a[i][j]==0)
      {
        if (a[i-1][j]==0)
        {
          addedge(id1,(i-1-1)*m+j,1);
          addedge((i-1-1)*m+j,id1,1);
		}
		else if (a[i-1][j]==1)
		  addedge((i-1-1)*m+j,id1,1);
		else if (a[i-1][j]==2)
		  addedge(id1,(i-1-1)*m+j,1);
	  }
	  else if (a[i][j]==1)
	  {
	    if (a[i-1][j]==2)
	      addedge(id1,(i-2)*m+j,1);
	    else if (a[i-1][j]==0)
	      addedge(id1,(i-2)*m+j,1);
	  }
	  else if (a[i][j]==2)
	  {
	    if (a[i-1][j]!=2)
	      addedge((i-2)*m+j,id1,1);
	  }
	}
	if (j>1)
	{
	  if (a[i][j]==0)
	  {
	    if (a[i][j-1]==0)
	    {
	      addedge((i-1)*m+j-1,id1,1);
	      addedge(id1,(i-1)*m+j-1,1);
		}
		else if (a[i][j-1]==1)
		  addedge((i-1)*m+j-1,id1,1);
		else if (a[i][j-1]==2)
		  addedge(id1,(i-1)*m+j-1,1);
	  }
	  else if (a[i][j]==1)
	  {
	    if (a[i][j-1]!=1)
	      addedge(id1,(i-1)*m+j-1,1);
	  }
	  else if (a[i][j]==2)
	  {
	    if (a[i][j-1]!=2)
	      addedge((i-1)*m+j-1,id1,1);
	  }
	}
	if (a[i][j]==1)
	  addedge(S,id1,INF);
	else if (a[i][j]==2)
	  addedge(id1,T,INF);
    }
  }
  int ans=0;
  while(bfs())
  {
    memset(cur,0,sizeof(cur));
    ans+=dfs(S,INF);
  }
  printf("%d\n",ans);
  return 0;
}

