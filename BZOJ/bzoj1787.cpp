#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 500009
using namespace std;

vector<int> g[MN];
int dep[MN],fa[MN][30];
bool vis[MN];
int pl;
int M,n;

void dfs(int u,int pre)
{
  vis[u]=true;
  dep[u]=dep[pre]+1;
  fa[u][0]=pre;
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i]])
      dfs(g[u][i],u);
}

void bz()
{
  int i,j;
  for (j=1;j<=M;j++)
    for (i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int LCA(int u,int v,int &s)
{
  if (dep[u]<dep[v])
    swap(u,v);
  for (int j=M;j>=0;j--)
    if (dep[fa[u][j]]>=dep[v])
    {
      s+=(1<<j);
      u=fa[u][j];
	}
  if (u==v)
    return u;
  for (int j=M;j>=0;j--)
    if (fa[u][j]!=fa[v][j])
    {
      s+=2*(1<<j);
      u=fa[u][j];
      v=fa[v][j];
	}
  s+=2;
  return fa[u][0];
}

int getans(int a,int b,int c,int &lca)
{
  int sum=0;
  lca=LCA(a,b,sum);
  int lca2=LCA(lca,c,sum);
  return sum;
}

int main()
{
  freopen("1787.in","r",stdin);
  freopen("1787.out","w",stdout);
  int i,j,k,m,ii=0,ca;
  int qus;
  scanf("%d%d",&n,&qus);
  M=(int)floor(log(n+0.01)/log(2.0));
  for (i=1;i<=n-1;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(vis,0,sizeof(vis));
  dep[0]=0;
  dfs(1,0);
  bz();
  while(qus--)
  {
    int a,b,c,lca;
    scanf("%d%d%d",&a,&b,&c);
    int ans=INF;
    int s=getans(a,b,c,lca);
    if (s<ans)
    {
      ans=s;
      pl=lca;
	}
	s=getans(b,c,a,lca);
	if (s<ans)
	{
	  ans=s;
	  pl=lca;
	}
	s=getans(c,a,b,lca);
	if (s<ans)
	{
	  ans=s;
	  pl=lca;
	}
	printf("%d %d\n",pl,ans);
  }
  return 0;
}

