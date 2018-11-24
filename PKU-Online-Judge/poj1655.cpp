#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> g[20006];
int fa[20006];
int s[20006];
int ans[20006];

void dfs(int u,int pre)
{
  s[u]=1;
  fa[u]=pre;
  for (int i=0;i<g[u].size();i++)
    if (g[u][i]!=pre)
    {
      dfs(g[u][i],u);
      s[u]+=s[g[u][i]];
	}
}

int main()
{
  freopen("1655.in","r",stdin);
  freopen("1655.out","w",stdout);
  int n,i,j,k,m,ca;
  scanf("%d",&ca);
  while(ca--)
  {
  	scanf("%d",&n);
    //memset(s,0,sizeof(s));
    for (i=0;i<=n;i++)
      g[i].clear();
    for (i=1;i<=n-1;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      g[u].push_back(v);
      g[v].push_back(u);
	}
	dfs(1,0);
	for (i=1;i<=n;i++)
	{
	  ans[i]=n-s[i];
	  for (j=0;j<g[i].size();j++)
	    if (g[i][j]!=fa[i])
	      ans[i]=max(ans[i],s[g[i][j]]);
	}
	k=1;
	for (i=2;i<=n;i++)
	  if (ans[i]<ans[k])
	    k=i;
	printf("%d %d\n",k,ans[k]);
  }
  return 0;
}
