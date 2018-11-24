#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char a[10][10];
int dp[10][(1<<9)+2];
int pre[10];

int fit(int s,int i)
{
  if (s&pre[i])
    return false;
  return true;
}

int count(int s)
{
  int ans=0;
  while(s)
  {
    ans+=(s&1);
    s>>=1;
  }
  return ans;
}

int main()
{
  freopen("1321.in","r",stdin);
  freopen("1321.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    if (n+m==-2)
      break;
    for (i=1;i<=n;i++)
      scanf("%s",a[i]+1);
    for (i=1;i<=n;i++)
    {
      pre[i]=0;
      for (j=1;j<=n;j++)
        if (a[i][j]=='.')
          pre[i]|=(1<<(n-j));
	}
	memset(dp,0,sizeof(dp));
	int full=(1<<n)-1;
	for (i=0;i<n;i++)
	  if (fit(1<<i,1))
	    dp[1][1<<i]=1;
	dp[1][0]=1;
	for (i=2;i<=n;i++)
	{
	  for (int s=0;s<=full;s++)
	    if (dp[i-1][s]>0)
	    {
	      dp[i][s]+=dp[i-1][s];
	      for (j=0;j<n;j++)
	        if ((!((1<<j)&s))&&fit(1<<j,i))
	          dp[i][s|(1<<j)]+=dp[i-1][s];
		}
	}
	int ans=0;
	for (i=0;i<=full;i++)
	  if (count(i)==m)
	   ans+=dp[n][i];
	printf("%d\n",ans);
  }
  return 0;
}
