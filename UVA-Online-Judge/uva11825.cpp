#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int st[20];
int pre[(1<<16)+3];
int dp[(1<<16)+3];
bool vis[(1<<16)+3];
int full;

int find(int s)
{
  if (vis[s])
    return dp[s];
  vis[s]=true;
  for (int s0=s;s0;s0=(s0-1)&s)
    if ((pre[s0])==full)
      dp[s]=max(dp[s],find(s^s0)+1);
  return dp[s];
}

int main()
{
  freopen("11825.in","r",stdin);
  freopen("11825.out","w",stdout);
  int n,i,j,k,m,ii=0;
  while(scanf("%d",&n)==1&&n)
  {
  	printf("Case %d: ",++ii);
    memset(pre,0,sizeof(pre));
    memset(st,0,sizeof(st));
	int top=0;
	for (i=0;i<n;i++)
    {
      st[top]|=(1<<i);
      scanf("%d",&m);
      while(m--)
      {
        int u;
        scanf("%d",&u);
        st[top]|=(1<<u);
	  }
	  top++;
	}
	full=(1<<top)-1;
	for (int s=0;s<=full;s++)
	  for (j=0;j<n;j++)
	    if (s&(1<<j))
	      pre[s]|=st[j];
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    printf("%d\n",find(full));
  }
  return 0;
}
