#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

vector<int> g[1005];
bool iscut[1005],ins[1005],vis[1005];
int low[1005],pre[1005],child[1005];
int N,dfn,T=0;

int dfs(int u,int fa)
{
  int lowu,lowv,son=0;
  lowu=pre[u]=++dfn;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      ++son;
      lowv=dfs(v,u);
      lowu=min(lowu,lowv);
      if (lowv>=pre[u])
      {
        child[u]++;
        iscut[u]=true;
      }
    }
    else if (v!=fa)
      lowu=min(lowu,pre[v]);
  }
  low[u]=lowu;
  if (fa==-1&&son==1) iscut[u]=false;
  if (iscut[u]&&fa!=-1) child[u]++;
  return lowu;
}

int main()
{
  freopen("1523.in","r",stdin);
  freopen("1523.out","w",stdout);  
  int u,v,i,j,w;
  scanf("%d",&u);
  while (u)
  {
    N=0;
    dfn=0;
    T++;
    memset(low,0,sizeof(low));
    memset(iscut,0,sizeof(iscut));
    memset(child,0,sizeof(child));
    memset(pre,0,sizeof(pre));
    memset(ins,0,sizeof(ins));
    memset(vis,0,sizeof(vis));
    for (i=0;i<1005;i++)g[i].clear();
    scanf("%d",&v);
    g[u].push_back(v);
    g[v].push_back(u);
    ins[u]=true;
    ins[v]=true;
    scanf("%d",&u);
    while(u)
    {
      scanf("%d",&v);
      g[u].push_back(v);
      g[v].push_back(u);
      ins[u]=true;
      ins[v]=true;
      scanf("%d",&u);
    }
    for (i=0;i<1001;i++)
      if (ins[i]&&(!pre[i]))
      {
        N++;
        dfs(i,-1);
      }
    bool flag=false;
    printf("Network #%d\n",T);
    for (i=0;i<1001;i++)
      if (iscut[i])
      {
        flag=true;
        printf("  SPF node %d leaves %d subnets\n",i,child[i]+N-1);
      }
    if (!flag) printf("  No SPF nodes\n");
    putchar('\n');
    scanf("%d",&u);
  }
  return 0;
}

