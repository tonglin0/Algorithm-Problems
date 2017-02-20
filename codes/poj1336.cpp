#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#define INF (int)1e9
#define MN 503
using namespace std;

int S,T;
int win[MN],lose[MN];
int a[27][27];
vector<int> anss;
int cur[MN];
int dis[MN];
bool vis[MN];
vector<int> g[MN];
struct edge{
	int from,to,c,f;
};
vector<edge> es;

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
  dis[S]=0;
  queue<int> q;
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
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(e.c-e.f,a)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0)
        return flow;
	}
  }
  return flow;
}

int main()
{
  freopen("1336.in","r",stdin);
  freopen("1336.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d%d",&win[i],&lose[i]);
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    anss.clear();
    S=0;
    for (int ii=1;ii<=n;ii++)
    {
      es.clear();
      bool flag=false;
      for (i=0;i<MN;i++)
        g[i].clear();
      int tot=0;
      for (j=1;j<=n;j++)
        tot+=a[ii][j];
      tot+=win[ii];
      int sum=0;
      int cnt=n;
      for (i=1;i<=n;i++)
        for (j=1;j<i;j++)
        {
          if (i==ii||j==ii)
            continue;
          sum+=a[i][j];
          cnt++;
          addedge(S,cnt,a[i][j]);
          addedge(cnt,i,INF);
          addedge(cnt,j,INF);
		}
	  T=cnt+1;
	  for (i=1;i<=n;i++)
	    if (i!=ii)
	    {
	      if (tot-win[i]<0)
	      {
	        flag=true;
	        break;
		  }
		  addedge(i,T,tot-win[i]);
		}
	  if (flag)
	    continue;
	  int ans=0;
	  while(bfs())
	  {
	    memset(cur,0,sizeof(cur));
	    ans+=dfs(S,INF);
	  }
	  if (ans>=sum)
	    anss.push_back(ii);
	}
	printf("%d",anss[0]);
	for (i=1;i<anss.size();i++)
	  printf(" %d",anss[i]);
    printf("\n");
  }
  return 0;
}
