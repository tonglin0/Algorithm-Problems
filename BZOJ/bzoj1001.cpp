#include<cstdlib>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#define INF (int)1e9
#define MN 1001*2001+101
using namespace std;

struct node{int v,w;};
vector<node> g[MN];
int h[MN],z[MN],x[MN],dis[MN];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
bool vis[MN];

void addedge(int u,int v,int w)
{
  node e;
  e.v=v;
  e.w=w;
  g[u].push_back(e);
  e.v=u;
  g[v].push_back(e);
}

int main()
{
  //freopen("1001.in","r",stdin);
  //freopen("1001.out","w",stdout);
  int n,i,j,k,m;
  memset(h,0,sizeof(h));
  memset(z,0,sizeof(z));
  memset(x,0,sizeof(x));
  scanf("%d%d",&n,&m);
  int N=n-1,M=(m-1)*2;
  int S=0,T=M*N+1;
  int mi=INF;
  for (i=1;i<=n*(m-1);i++)
  {  scanf("%d",&h[i]);mi=min(mi,h[i]);}
  for (i=1;i<=(n-1)*m;i++)
  {  scanf("%d",&z[i]);mi=min(mi,z[i]);}
  for (i=1;i<=(n-1)*(m-1);i++)
  {  scanf("%d",&x[i]);mi=min(mi,x[i]);}
  if (n==1||m==1)
  {
    printf("%d\n",mi);
    return 0;
  }
  int d=1;
  for (i=1;i<=N;i++)
  {
    addedge((i-1)*M+1,S,z[d]);
    d+=m;
  }
  d=n*(m-1)-(m-1)+1;
  for (i=1;i<=M-1;i+=2)
  {
    addedge((N-1)*M+i,S,h[d]);
    d++;
  }
  d=1;
  for (j=2;j<=M;j+=2)
  {
    addedge(j,T,h[d]);
    d++;
  }
  d=m;
  for (i=1;i<=N;i++)
  {
    addedge((i-1)*M+M,T,z[d]);
    d+=m;
  }
  d=m;
  for (i=1;i<N;i++)
    for (j=1;j<=M-1;j+=2)
    {
      int u=(i-1)*M+j;
      int v=i*M+j+1;
      int w=h[d];
      d++;
      addedge(u,v,w);
    }
  d=2;
  for (i=1;i<=N;i++)
  {
    for (j=2;j<M;j+=2)
    {
      int u=(i-1)*M+j;
      int v=(i-1)*M+j+1;
      int w=z[d];
      d++;
      addedge(u,v,w);
    }
    d=i*m+2;
  }
  d=1;
  for (i=1;i<=N;i++)
    for (j=1;j<=M-1;j+=2)
    {
      int u=(i-1)*M+j;
      int v=u+1;
      int w=x[d];
      d++;
      addedge(u,v,w);
    }
  int s=0;
  memset(vis,0,sizeof(vis));
  memset(dis,60,sizeof(dis));
  //vis[S]=true;
  dis[S]=0;
  q.push(make_pair(0,S));
  while(!q.empty())
  {
    pii e=q.top();q.pop();
    if (vis[e.second]) continue;
    vis[e.second]=true;
    int u=e.second;
    //if (u==T) break;
    for (i=0;i<g[u].size();i++)
      if (!vis[g[u][i].v]&&dis[g[u][i].v]>dis[u]+g[u][i].w)
        q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
  }
  //for (i=S;i<=T;i++)
    //printf("dis[%d]=%d\n",i,dis[i]);
  printf("%d\n",dis[T]);
  return 0;
}
