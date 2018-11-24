#include<cstdio>
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

using namespace std;

bool vis[15];
int n;
int a[15];

void dfs(int k,int s)
{
  if (k==n+1)
  {
    int cnt=0;
    for (int i=1;i<=n;i++)
      if (vis[i])
        cnt++;
    if (cnt==6)
    {
      int i;
      for (i=1;i<=n;i++)
        if (vis[i])
        {
          printf("%d",a[i]);
          break;
		}
	  for (i=i+1;i<=n;i++)
	    if (vis[i])
	      printf(" %d",a[i]);
	  printf("\n");
	}
	return ;
  }
  vis[k]=true;
  dfs(k+1,s+1);
  vis[k]=false;
  dfs(k+1,s);
}

int main()
{
  freopen("lotto.in","r",stdin);
  freopen("lotto.out","w",stdout);
  bool first=true;
  int i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    if (n==0)
      break;
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    if (!first)
      printf("\n");
    first=false;
    memset(vis,0,sizeof(vis));
    dfs(1,0);
  }
}

