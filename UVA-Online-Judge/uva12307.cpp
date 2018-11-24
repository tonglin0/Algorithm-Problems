#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
#define lint long long
using namespace std;

lint d1[40][909],d2[40][909];
lint l1[40],l2[40];

int main()
{
  freopen("12307.in","r",stdin);
  freopen("12307.out","w",stdout);
  lint n,i,j,k,m;
  memset(l1,0,sizeof(l1));
  memset(l2,0,sizeof(l2));
  l1[1]=l1[2]=1;
  l2[1]=l2[2]=2;
  for (i=3;i<=30;i+=2)
  {
    l1[i]=l1[i+1]=l1[i-1]+2;
    l2[i]=l2[i+1]=l2[i-1]+2;
  }
  while(scanf("%lld%lld",&n,&k)==2)
  {
    if (n==0&&k==0)
      break;                        
    lint ans=0;
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    for (i=0;i<=n;i++)
      d1[i][0]=d2[i][0]=1;
    for (i=1;i<=n;i++)
      for (j=1;j<=k;j++)
      {
        d1[i][j]=d1[i-1][j]+(l1[i]-j+1)*d1[i-1][j-1];
        d2[i][j]=d2[i-1][j]+(l2[i]-j+1)*d2[i-1][j-1];
	  }
	for (i=0;i<=k;i++)
	  ans+=d1[n][i]*d2[n-1][k-i];
	printf("%lld\n",ans);
  }
  //printf("%.6lf\n",clock()/(double)CLOCKS_PER_SEC);
  return 0;
}
