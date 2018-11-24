#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int w[205];
int top;
int vi[205],next[205],head[205];
int f[205][1009][2];
bool vis[205];
int step;

void addedge(int u,int v)
{
  vi[top]=v;
  next[top]=head[u];
  head[u]=top++;
}

void dfs(int u)
{
  vis[u]=true;
  for (int i=0;i<=step;i++)
    f[u][i][0]=f[u][i][1]=w[u];
  for (int i=head[u];i!=-1;i=next[i])
  {
    int v=vi[i];
    if (vis[v])
      continue;
    dfs(v);
    for (int j=step;j>=0;j--)
      for (int k=step;k>=0;k--)
      {
        f[u][j+k+2][0]=max(f[u][j+k+2][0],f[u][j][0]+f[v][k][0]);
        f[u][j+k+2][1]=max(f[u][j+k+2][1],f[u][j][1]+f[v][k][0]);
        f[u][j+k+1][1]=max(f[u][j+k+1][1],f[u][j][0]+f[v][k][1]);
      }
  }
}

int main()
{
  freopen("2486.in","r",stdin);
  freopen("2486.out","w",stdout);
  int n,i,j,m;
  while(scanf("%d%d",&n,&step)==2)
  {
    top=0;
    memset(head,-1,sizeof(head));
    for (i=1;i<=n;i++)
      scanf("%d",&w[i]);
    for (i=1;i<n;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      addedge(u,v);
      addedge(v,u);
    }
    memset(f,-1,sizeof(f));
    memset(vis,0,sizeof(vis));
    dfs(1);
    printf("%d\n",f[1][step][1]);
  }
  return 0;
}
