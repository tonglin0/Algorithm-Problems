#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct treenode{
	int v,w;
};
vector<treenode> g[10004];
int fa[10005];
int il[10005];
struct node{
	int from,w;
};
node ms1[10005],ms2[10005];
int n;
int ans[10005];

void bfs()
{
  queue<int> q;
  for (int i=1;i<=n;i++)
    if (!il[i])
      q.push(i);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
      if (g[u][i].w+ms1[g[u][i].v].w>=ms1[u].w)
      {
        ms2[u]=ms1[u];
        ms1[u].w=g[u][i].w+ms1[g[u][i].v].w;
        ms1[u].from=g[u][i].v;
	  }
	  else if (g[u][i].w+ms1[g[u][i].v].w>ms2[u].w)
	  {
	    ms2[u].w=g[u][i].w+ms1[g[u][i].v].w;
	    ms2[u].from=g[u][i].v;
	  }
	il[fa[u]]--;
	if (!il[fa[u]])
	  q.push(fa[u]);
  }
}

void dfs(int u,int pre,int d)
{
  int tmp;
  if (ms1[fa[u]].from!=u)
    tmp=ms1[fa[u]].w;
  else
    tmp=ms2[fa[u]].w;
  tmp+=d;
  if (tmp>=ms1[u].w)
  {
    ms2[u]=ms1[u];
    ms1[u].from=0;
    ms1[u].w=tmp;
  }
  else if (tmp>=ms2[u].w)
  {
    ms2[u].from=0;
    ms2[u].w=tmp;
  }
  ans[u]=ms1[u].w;
  for (int i=0;i<g[u].size();i++)
    dfs(g[u][i].v,u,g[u][i].w);
}

int main()
{
  freopen("2196.in","r",stdin);
  freopen("2196.out","w",stdout);
  int i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    for (i=0;i<=n;i++)
      g[i].clear();
    memset(il,0,sizeof(il));
    for (i=2;i<=n;i++)
    {
      int u,w;
      scanf("%d%d",&u,&w);
      treenode tmp;
      tmp.v=i;tmp.w=w;
      g[u].push_back(tmp);
      fa[i]=u;
      il[u]++;
	}
	memset(ms1,0,sizeof(ms1));
	memset(ms2,0,sizeof(ms2));
	bfs();
	memset(ans,0,sizeof(ans));
	ans[1]=ms1[1].w;
	for (i=0;i<g[1].size();i++)
	  dfs(g[1][i].v,1,g[1][i].w);
	for (i=1;i<=n;i++)
	  printf("%d\n",ans[i]);
  }
  return 0;
}
