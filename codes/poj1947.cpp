#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF (int)1e9
#define MN 154
using namespace std;

int f[MN][MN];
int vi[MN],next[MN],head[MN];
int top;
int s[MN];
int fa[MN];

void addedge(int u,int v)
{
  vi[top]=v;
  next[top]=head[u];
  head[u]=top++;
}

void dfs(int u)
{
  for (int i=head[u];i!=-1;i=next[i])
  {
    int v=vi[i];
    dfs(v);
    for (int j=s[u];j>=1;j--)
      for (int k=s[v];k>=1;k--)
        f[u][j+k]=min(f[u][j+k],f[u][j]+f[v][k]-1);
    s[u]+=s[v];
  }
}

int main()
{
  freopen("1947.in","r",stdin);
  freopen("1947.out","w",stdout);
  int n,i,j,k,m,p;
  scanf("%d%d",&n,&p);
  memset(head,-1,sizeof(head));
  top=0;
  memset(fa,0,sizeof(fa));
  memset(s,0,sizeof(s));
  for (i=1;i<n;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v);
    s[u]++;
    fa[v]=u;
  }
  if (p==0||p==n)
  {
    printf("0\n");
    return 0;
  }
  for (i=0;i<=n;i++)
    for (j=0;j<=n;j++)
      f[i][j]=INF;
  for (i=1;i<=n;i++)
    f[i][1]=s[i];
  for (i=1;i<=n;i++)
    s[i]=1;
  int root=1;
  while(fa[root]!=0)
    root=fa[root];
  dfs(root);
  k=1;
  for (i=2;i<=n;i++)
    if (f[i][p]+1<f[k][p])
      k=i;
  printf("%d\n",k==1?f[k][p]:(f[k][p]+1));
  return 0;
}
