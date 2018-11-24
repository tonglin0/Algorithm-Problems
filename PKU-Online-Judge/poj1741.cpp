#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF (int)1e9
#define MN 10009
using namespace std;

struct node{
       int v,w;
};
vector<node> g[MN];
bool vis[MN];
int ans;
int s[MN],f[MN];
int depth[MN];
int cnt,k;
int A[MN];

int build_tree(int u,int pre)
{
  s[u]=1;
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&g[u][i].v!=pre)
      s[u]+=build_tree(g[u][i].v,u);
  return s[u];
}

int find_weight(int u,int n,int pre)
{
  int ans=INF;
  f[u]=n-s[u];
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&g[u][i].v!=pre)
    {
      ans=min(ans,find_weight(g[u][i].v,n,u));
      f[u]=max(f[u],s[g[u][i].v]);
    }
  ans=min(ans,f[u]);
  return ans;
}

void find_root(int u,int pre,int ans,int &root)
{
  if (f[u]==ans)
  {
    root=u;
    return ;
  }
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&g[u][i].v!=pre)
      find_root(g[u][i].v,u,ans,root);
}

void find_depth(int u,int pre,int d)
{
  depth[u]=depth[pre]+d;
  A[++cnt]=depth[u];
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].v]&&g[u][i].v!=pre)
      find_depth(g[u][i].v,u,g[u][i].w);
}

void work(int u)
{
  s[u]=build_tree(u,0);
  int n=s[u];
  if (n==1) return;
  int root=u;
  int mins=find_weight(u,n,0);
  find_root(u,0,mins,root);          
  depth[root]=0;
  cnt=1;
  A[1]=0;
  for (int i=0;i<g[root].size();i++)
    if (!vis[g[root][i].v])
      find_depth(g[root][i].v,root,g[root][i].w);
  sort(A+1,A+cnt+1);
  int l=1,r=1;
  while(r<=cnt&&A[l]+A[r]<=k)
    r++;
  r--;
  while(l<r)
  {
    ans+=(r-l);
    l++;
    while(r>l&&A[r]+A[l]>k)
      r--;
  }
  vis[root]=true;
  for (int i=0;i<g[root].size();i++)
    if (!vis[g[root][i].v])
    {
      cnt=0;
      //A[1]=0;
      depth[root]=0;
      find_depth(g[root][i].v,root,g[root][i].w);
      sort(A+1,A+cnt+1);
      l=1;r=1;
      while(r<=cnt&&A[l]+A[r]<=k)
        r++;
      r--;
      while(l<r)
      {
        ans-=(r-l);
        l++;
        while(r>l&&A[r]+A[l]>k)
          r--;
      }
    }
  for (int i=0;i<g[root].size();i++)
    if (!vis[g[root][i].v])
      work(g[root][i].v);
}

int main()
{
  freopen("1741.in","r",stdin);
  freopen("1741.out","w",stdout);
  int n,i,j,m;
  while(scanf("%d%d",&n,&k)==2&&(n+k))
  {
    for (i=0;i<=n;i++)
      g[i].clear();
    memset(vis,0,sizeof(vis));
    for (i=1;i<n;i++)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      node tmp;
      tmp.v=v;tmp.w=w;
      g[u].push_back(tmp);
      tmp.v=u;
      g[v].push_back(tmp);
    }
    ans=0;
    work(1);
    printf("%d\n",ans);
  }
  return 0;
}
