#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint c[600][600];
lint n;

int main()
{
  freopen("1073.in","r",stdin);
  freopen("1073.out","w",stdout);
  lint i,j,k,m;
  memset(c,0,sizeof(c));
  c[0][0]=1;
  for (i=1;i<=590;i++)
  {
    c[i][0]=c[i][i]=1;
    for (j=1;j<i;j++)
      c[i][j]=c[i-1][j-1]+c[i-1][j];
  }
  lint ii=0;
  while(scanf("%lld",&n)==1)
  {
    if (n==0) break;
	printf("Case %d: ",++ii);
    if (n<=3||(n&1)) 
      printf("0\n");
    else if (n==4)
      printf("1\n");
    else
      printf("%lld\n",2*c[(n+2)/2][(n-6)/2]+c[(n+2)/2][(n-4)/2]);
  }
  return 0;
}
