#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define MN 502*502+100
using namespace std;

typedef pair<int,int> pii;
struct node{int v,w;};
vector<node> g[MN];
int h[MN],h2[MN],z[MN],z2[MN];
int dis[MN];
bool ins[MN],vis[MN];

void addedge(int u,int v,int w)
{
  node x;
  x.v=v;
  x.w=w;
  g[u].push_back(x);
}

int main()
{
  int n,i,j,k,m;
  //freopen("altitude.in","r",stdin);
  //freopen("altitude.out","w",stdout);
  memset(h,0,sizeof(h));
  memset(h2,0,sizeof(h2));
  memset(z2,0,sizeof(z2));
  memset(z,0,sizeof(z));
  scanf("%d",&n);
  for (i=1;i<=n*(n+1);i++)
    scanf("%d",&h[i]);
  for (i=1;i<=n*(n+1);i++)
    scanf("%d",&z[i]);
  for (i=1;i<=n*(n+1);i++)
    scanf("%d",&h2[i]);
  for (i=1;i<=n*(n+1);i++)
    scanf("%d",&z2[i]);
  int S=0,T=(n+1)*(n+1)+1;
  for (i=1;i<=n;i++)
  {
    int v=(i-1)*n+1;
    int w=z[(i-1)*(n+1)+1];
    addedge(S,v,w);
    w=z2[(i-1)*(n+1)+1];
    addedge(v,S,w);
  }
  for (i=1;i<=n;i++)
  {
    int v=(n-1)*n+i;
    int w=h[n*n+i];
    addedge(S,v,w);
    w=h2[n*n+i];
    addedge(v,S,w);
  }
  for (i=1;i<=n;i++)
  {
    int v=i;
    int w=h[i];
    addedge(v,T,w);
    w=h2[i];
    addedge(T,v,w);
  }
  for (i=1;i<=n;i++)
  {
    int v=(i-1)*n+n;
    int w=z[(i-1)*(n+1)+n+1];
    addedge(v,T,w);
    w=z2[(i-1)*(n+1)+n+1];
    addedge(T,v,w);
  }
  for(i=1;i<=n-1;i++)
    for (j=1;j<=n;j++)
    {
      int u=(i-1)*n+j;
      int v=u+n;
      int w=h2[u+n];
      addedge(u,v,w);
      w=h[u+n];
      addedge(v,u,w);
    }
  for (i=1;i<=n;i++)
    for (j=1;j<=n-1;j++)
    {
      int u=(i-1)*n+j;
      int v=u+1;
      int w=z[v+i-1];
      addedge(u,v,w);
      w=z2[v+i-1];
      addedge(v,u,w);
    }
  memset(vis,0,sizeof(vis));
  priority_queue<pii,vector<pii>,greater<pii> > q;
  q.push(make_pair(0,S));
  memset(dis,60,sizeof(dis));
  dis[S]=0;
  while(!q.empty())
  {
    pii x=q.top();q.pop();
    int u=x.second;
    if (vis[u]) continue;
    vis[u]=true;
    if (u==T) break;
    for (i=0;i<g[u].size();i++)
      if (!vis[g[u][i].v]&&dis[u]+g[u][i].w<dis[g[u][i].v])
        q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
  }
  printf("%d\n",dis[T]);
  /*queue<int> q;
  q.push(S);
  memset(dis,60,sizeof(dis));
  memset(ins,0,sizeof(ins));
  ins[S]=true;
  dis[S]=0;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (i=0;i<g[u].size();i++)
      if (g[u][i].w+dis[u]<dis[g[u][i].v])
      {
        dis[g[u][i].v]=dis[u]+g[u][i].w;
        if (!ins[g[u][i].v])
        {
          ins[g[u][i].v]=true;
          q.push(g[u][i].v);
        }
      }
  }
  memset(q,0,sizeof(q));
  int f=50*MN;
  int r=f+1;
  q[r]=S;
  while(f<r) 
  {
    f++;
    int u=q[f];
    ins[u]=false;
    for (i=0;i<g[u].size();i++)
      if (dis[u]+g[u][i].w<dis[g[u][i].v])
      {
        dis[g[u][i].v]=dis[u]+g[u][i].w;
        if (!ins[g[u][i].v])
        {
          ins[g[u][i].v]=true;
          int v=q[f+1];
          if (dis[g[u][i].v]<dis[v])
          {
            q[f]=g[u][i].v;
            f--;
          }
          else
          {
            r++;
            q[r]=g[u][i].v;
          }
        }
      }
  }*/
  //printf("%d\n",dis[T]);
  return 0;
}
