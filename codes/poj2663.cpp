#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int f[34];

int main()
{
  freopen("2663.in","r",stdin);
  freopen("2663.out","w",stdout);
  int n,i,j,k,m;
  f[0]=1;
  f[2]=3;
  for (i=4;i<=30;i+=2)
  {
    f[i]=3*f[i-2];
    n=4;
    while(i-n>=0)
    {
      f[i]+=2*f[i-n];
	  n+=2;
	}
  }
  while(scanf("%d",&n)==1)
  {
    if (n<0)
      break;
    if (n&1)
      printf("0\n");
    else
	  printf("%d\n",f[n]);
  }
  return 0;
}
