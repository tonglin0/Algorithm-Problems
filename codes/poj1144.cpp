#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cctype>
using namespace std;

vector<int> g[103];
bool iscut[103];
int low[103],pre[103];
int dfsclock;

int dfs(int u,int fa)
{
  int lowu,lowv,child=0;
  pre[u]=lowu=++dfsclock;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!pre[v])
    {
      child++;
      lowv=dfs(v,u);
      lowu=min(lowu,lowv);
      if (lowv>=pre[u]) iscut[u]=true;
    }
    else if (pre[v]<pre[u]&&v!=fa)
      lowu=min(lowu,pre[v]);
  }
  if (child==1&&fa<0) iscut[u]=false;
  low[u]=lowu;
  return lowu;
}
int number(char &ch)
{
  int x=ch-'0';
  ch=getchar();
  while(isdigit(ch))
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return x;
}
int main()
{
  //printf("%d\n",' ');
  //freopen("poj1144.in","r",stdin);
  //freopen("poj1144.out","w",stdout);
  int i,j,k,m,n;
  scanf("%d",&n);
  while(n)
  {
    for (i=0;i<103;i++) g[i].clear();
    scanf("%d",&m);
    while(m)
    {
      char ch;
      ch=getchar();
      for(;;)
      {
        //ch=getchar();
        while (ch==32) ch=getchar();
        if (isdigit(ch)) {int v=number(ch);g[m].push_back(v);g[v].push_back(m);}
          else break; 
      }
      scanf("%d",&m);
    }
    memset(iscut,0,sizeof(iscut));
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    dfsclock=0;
    dfs(1,-1);
    int ans=0;
    for (i=1;i<=n;i++) if (iscut[i]) ans++;
    printf("%d\n",ans); 
    scanf("%d",&n);
  }
  return 0;  
}
