#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
  freopen("1384.in","r",stdin);
  freopen("1384.out","w",stdout);
  int n,i,j,k,m,p,ii=0;
  while(scanf("%d%d",&p,&n)==2&&(n+p))
  {
    int ans=1;
    while(n)
    {
      ans=(ans*(n%p+1))%10000;
      n/=p;
	}
	/*printf("Case %d:  ",++ii);
	if (ans<10)
	  printf("000%d\n",ans);
	else if (ans>=10&&ans<100)
	  printf("00%d\n",ans);
	else if (ans>=100&&ans<1000)
	  printf("0%d\n",ans);
	else
	  printf("%d\n",ans);*/
	printf("Case %d: %04d\n",++ii,ans);
  }
  return 0;
}
