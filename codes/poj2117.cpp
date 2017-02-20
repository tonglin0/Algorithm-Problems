#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

bool iscut[10005];
int child[10005],low[10005],pre[10005];
vector<int> g[10005];
int dfsclock;

int dfs(int u,int fa)
{
  int lowu,lowv;
  lowu=pre[u]=++dfsclock;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      //child[u]++;
      lowv=dfs(v,u);
      lowu=min(lowu,lowv);   
      if (lowv>=pre[u]) {iscut[u]=true;child[u]++;}
    }
    else if (v!=fa) lowu=min(lowu,pre[v]);
  }
  low[u]=lowu;
  if (child[u]==1&&fa==-1) iscut[u]=false;
  if (fa!=-1) child[u]++;
  if (g[u].size()==0) iscut[u]=true;
  return lowu;
}

int main()
{
  freopen("2117.in","r",stdin);
  freopen("2117.out","w",stdout);
  int n,i,j,m;
  scanf("%d%d",&n,&m);
  while(!(n==0&&m==0))
  {
    for (i=0;i<10005;i++) g[i].clear();
    for (i=1;i<=m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int N=0;
    dfsclock=0;
    memset(iscut,0,sizeof(iscut));
    memset(pre,0,sizeof(pre));
    memset(child,0,sizeof(child));
    memset(low,0,sizeof(low));
    for (i=0;i<n;i++)
      if (!pre[i])
      {
        N++;
        dfs(i,-1);
      }
    int M=0;
    for (i=0;i<n;i++)
      if (iscut[i]) {child[i]+=N-1;M=max(M,child[i]);}//M=max(M,child[i]+N-1);}
        else {M=max(M,N);child[i]=N;}
    /*
    bool flag=false;
    for (i=0;i<n;i++) if (iscut[i]){flag=true;M=max(M,child[i]);}
    if (!flag) M=max(M,1);*/ 
    printf("%d\n",M);
    //for (i=0;i<n;i++) printf("NO.%d %d iscut? %d\n",i,child[i],iscut[i]); 
    scanf("%d%d",&n,&m);
  }
  return 0;
}
