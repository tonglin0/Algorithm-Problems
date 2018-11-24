#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
  freopen("1315.in","r",stdin);
  freopen("1315.out","w",stdout);
  int n,i,j,k,T,m,s;
  scanf("%d",&T);
  while(T--)//while(scanf("%d",&n)==1)
  {
  	scanf("%d",&n);
    if (n==1)
    {
      printf("0\n");
      continue;
	}
	if (n==2)
	{
	  printf("0\n");
	  continue;
	}
	i=2;j=n-1;
	k=1;
	int ans=0;
	while(i<j)
	{
	  ans=ans+2*k;
	  i++;
	  j--;
	  k++;
	}
	if (i==j)
	  ans+=k;
	printf("%d\n",ans);
  }
  printf("%.2lf\n",clock()/(double)CLOCKS_PER_SEC);
  return 0;
}
