#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cctype>
#include<queue>
#include<cstring>
#define INF (int)1e9
#define MN 604
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[MN];
int cur[MN],dis[MN],sc[MN];
bool vis[MN];
int T;

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
  memset(dis,0,sizeof(dis));
  memset(vis,0,sizeof(vis));
  queue<int> q;
  vis[0]=true;
  q.push(0);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&!vis[e.to])
      {
        dis[e.to]=dis[u]+1;
        vis[e.to]=true;
        q.push(e.to);
      }
    }
  }
  return vis[T];
}

int dfs(int u,int a)
{
  if (u==T||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    edge &e=es[g[u][i]];
    if (dis[e.to]==dis[u]+1&&(f=dfs(e.to,min(a,e.c-e.f)))>0)
    {
      flow+=f;
      a-=f;
      e.f+=f;
      es[g[u][i]^1].f-=f;
      if (a==0) return flow;
    }
  }
  return flow;
}

int main()
{
  int TC,n,i,j,m,k;
  //freopen("2699.in","r",stdin);
  //freopen("2699.out","w",stdout);
  scanf("%d",&TC);
  while(TC--)
  {
    n=0;
    int s=0;
    memset(sc,0,sizeof(sc));
    es.clear();
    for (i=0;i<MN;i++) g[i].clear();
    char ch;
    ch=getchar();
    while(!isdigit(ch)) 
      ch=getchar();
    while(ch==' '||isdigit(ch))
    {
      if (ch==' ') ch=getchar();
      else
      {
        sc[++n]=ch-'0';
        s+=sc[n];
        ch=getchar();
      }
    }
    int r,l;
    for (i=n-1;i>=1;i--)
      if (sc[i]!=sc[i+1])
        break;
    r=i;
    for (i=1;i<=n-1;i++)
      if (sc[i]>=n-i)
        break;
    l=i;
    T=401;
    bool flag=true;
    //if (l>r) 
      //flag=false;
    //if (flag)
    for (i=r;i>=l;i--)
    {
      es.clear();
      for (j=0;j<MN;j++)
        g[j].clear();
      for (j=1;j<=n;j++)
        addedge(j,T,sc[j]);
      for (j=1;j<=n-1;j++)
        for (k=j+1;k<=n;k++)
        {
          addedge(0,j*n+k,1);  
          if (sc[k]>sc[j]&&j>=i)
            addedge(j*n+k,j,1);
          else
          {
            addedge(j*n+k,j,1);
            addedge(j*n+k,k,1);
          }
        }
      int ans=0;
      while(bfs())
      {
        memset(cur,0,sizeof(cur));
        ans+=dfs(0,INF);
      }
      if (ans<s)
        break;
    }
    printf("%d\n",n-i);
 /*
    if (i<r)
      printf("%d\n",n-i);
    else 
      printf("%d\n",n-r);*/
    //if (flag) printf("%d\n",n-i);
      //else printf("%d\n",n-r);
    //printf("r=%d\n",r);
  }
  return 0;
}
