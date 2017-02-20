#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f;};
vector<edge> es;
vector<int> g[450];
int hs[203],into[450],ls[23],up[203][23],down[203][23],cur[450],dis[450];
bool vis[450];
int T,S,SS,TT;

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
  memset(dis,0,sizeof(dis));
  queue<int> q;
  vis[SS]=true;
  q.push(SS);
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
  return vis[TT];
}

int dfs(int u,int a)
{
  if (u==TT||a==0) return a;
  int flow=0,f;
  for (int i=cur[u];i<g[u].size();i++)
  {
    cur[u]=i;
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
  int TC,n,i,j,k,m;
  //freopen("2396.in","r",stdin);
  //freopen("2396.out","w",stdout);
  scanf("%d",&TC);
  while(TC--)
  {
    scanf("%d%d",&n,&m);
    memset(up,60,sizeof(up));
    memset(down,0,sizeof(down));
    es.clear();
    memset(into,0,sizeof(into));
    for (i=0;i<450;i++) g[i].clear();
    memset(hs,0,sizeof(hs));
    memset(ls,0,sizeof(ls));
    for (i=1;i<=n;i++) 
      scanf("%d",&hs[i]);
    for (i=1;i<=m;i++)
      scanf("%d",&ls[i]);
    scanf("%d",&k);
    bool flag=true;
    for (i=1;i<=k;i++)
    {
      int d,u,v;
      scanf("%d%d",&u,&v);
      char ch=getchar();
      ch=getchar();
      scanf("%d",&d);
      if (u!=0&&v!=0)
      {
        if (ch=='>')
          down[u][v]=max(d+1,down[u][v]);
        else if (ch=='<')
          up[u][v]=min(d-1,up[u][v]);
        else
        {
          if (down[u][v]>d||up[u][v]<d)
            flag=false;
          else
            down[u][v]=up[u][v]=d;
        }
      }
      else if (u==0&&v!=0)
      {
        if (ch=='>')
          for (j=1;j<=n;j++)
            down[j][v]=max(d+1,down[j][v]);
        else if (ch=='<')
          for (j=1;j<=n;j++)
            up[j][v]=min(d-1,up[j][v]);
        else if (ch=='=')
        {
          for (j=1;j<=n;j++)
            if (down[j][v]>d||up[j][v]<d)
              flag=false;
            else
              down[j][v]=up[j][v]=d;
        }
      }
      else if (u!=0&&v==0)
      {
        if (ch=='>')
          for (j=1;j<=m;j++)
            down[u][j]=max(d+1,down[u][j]);
        else if (ch=='<')
          for (j=1;j<=m;j++)
            up[u][j]=min(d-1,up[u][j]);
        else if (ch=='=')
          for (j=1;j<=m;j++)
            if (down[u][j]>d||up[u][j]<d)
              flag=false;
            else 
              down[u][j]=up[u][j]=d;
      }
      else if (u==0||v==0)
      {
        if (ch=='>')
          for (j=1;j<=n;j++)
            for (int ii=1;ii<=m;ii++)
              down[j][ii]=max(d+1,down[j][ii]);
        else if (ch=='<')
          for (j=1;j<=n;j++)
            for (int ii=1;ii<=m;ii++)
              up[j][ii]=min(d-1,up[j][ii]);
        else if (ch=='=')
          for (j=1;j<=n;j++)
            for (int ii=1;ii<=m;ii++)
              if (down[j][ii]>d||up[j][ii]<d)
                flag=false;
              else
                down[j][ii]=up[j][ii]=d;
      }
      
    }
    if (!flag)
    {
      printf("IMPOSSIBLE\n\n");
      continue;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        if (up[i][j]<down[i][j])
          flag=false;
    if (!flag)
    {
      printf("IMPOSSIBLE\n\n");
      continue;
    }
    S=0;T=n+m+1;
    SS=T+1;
    TT=SS+1;
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=m;j++)
      {
        //s+=down[i][j];
        addedge(i,j+n,up[i][j]-down[i][j]);
        into[j+n]+=down[i][j];
        into[i]-=down[i][j];
      }
    }
    for (i=1;i<=n;i++)
      into[i]+=hs[i];
    for (j=1;j<=m;j++)
      into[j+n]-=ls[j];
    int s=0;
    for (i=1;i<=n+m;i++)
      if (into[i]>0)
      {
        s+=into[i];
        addedge(SS,i,into[i]);
      }
      else if (into[i]<0)
        addedge(i,TT,-into[i]);
    int ans=0;
    while(bfs())
    {
      memset(cur,0,sizeof(cur));
      ans+=dfs(SS,INF);
    }
    if (ans!=s)
    {
      printf("IMPOSSIBLE\n\n");
      continue;
    }
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=m;j++)
      {
        for (int ii=0;ii<g[i].size();ii++)
          if (es[g[i][ii]].to==j+n)
          {
            printf("%d ",es[g[i][ii]].f+down[i][j]);
            break;
          }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
