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
#define f(i,j) dp[i+6001][j]
using namespace std;

int dp[12005][2];
int aa[1004];

int aabs(int x){if (x<0) return -x;return x;}

int main()
{
  freopen("1717.in","r",stdin);
  freopen("1717.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  for (i=-6000;i<=6000;i++)
    f(i,0)=INF;
  f(0,0)=0;
  scanf("%d",&n);
  int x=1;
  int r=0,l=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&aa[i],&k);
    aa[i]-=k;
    r+=aabs(aa[i]);
    l-=aabs(aa[i]);
  }
  l--;r++;
  for (i=1;i<=n;i++)
  {
  	int a=aa[i];
    for (j=l;j<=r;j++)
      if (j-a<=r&&j-a>=l&&j+a<=r&&j+a>=l)
	    f(j,x)=min(f(j-a,x^1),f(j+a,x^1)+1);
      else if (j-a<=r&&j-a>=l)
        f(j,x)=f(j-a,x^1);
      else if (j+a<=r&&j+a>=l)
        f(j,x)=f(j+a,x^1)+1;
	x^=1;
  }
  for (i=0;i<=6000;i++)
    if (f(i,x^1)<INF||f(-i,x^1)<INF)
    {
      printf("%d\n",min(f(i,x^1),f(-i,x^1)));
      return 0;
	}
  return 0;
}

