#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MN 58
#define INF (int)1e9
using namespace std;

char ch[60];
struct edge{
	int from,to,c,f;
};
vector<edge> es,es2;
vector<int> g[MN],g2[MN];
int cur[MN],dis[MN];
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
  freopen("3504.in","r",stdin);
  freopen("3504.out","w",stdout);
  int n,i,j,k,m,a1,a2,an,b1,b2,bn;
  while(scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn)==7)
  {
    es.clear();
    for (i=0;i<MN;i++)
      g[i].clear();
    for (i=0;i<n;i++)
    {
      scanf("%s",ch);
      for (j=0;j<n;j++)
        if (ch[j]=='O')
        {
          addedge(i,j,1);
		}
		else if (ch[j]=='N')
		{
		  addedge(i,j,INF);
		}
	}
	es2=es;
	for (i=0;i<MN;i++)
	  g2[i]=g[i];
	S=n;T=n+1;
	addedge(S,a1,an);
	addedge(a2,T,an);
	addedge(S,b1,bn);
	addedge(b2,T,bn);
	int ans=0;
	while(bfs())
	{
	  memset(cur,0,sizeof(cur));
	  ans+=dfs(S,INF);
	}
	if (ans!=an+bn)
	{
	  printf("No\n");
	  continue;
	}
	ans=0;
	es=es2;
    for (i=0;i<MN;i++)
      g[i]=g2[i];
	addedge(S,a1,an);
	addedge(a2,T,an);
	addedge(S,b2,bn);
	addedge(b1,T,bn);
	while(bfs())
	{
	  memset(cur,0,sizeof(cur));
	  ans+=dfs(S,INF);
	}
	if (ans==an+bn)
	  printf("Yes\n");
	else
	  printf("No\n");
  }
  return 0;
}
